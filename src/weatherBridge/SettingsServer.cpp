#include "weatherBridge/SettingsServer.hpp"

static constexpr auto WIFI_SSID = "wifi_ssid";
static constexpr auto WIFI_PASSWORD = "wifi_password";
static constexpr auto WIFI_AP_SSID = "wifi_ap_ssid";
static constexpr auto WIFI_AP_PASSWORD = "wifi_ap_password";
static constexpr auto TIMEZONE_STR = "timezone_str";
static constexpr auto PWSWEATHER_STATION_ID = "pwsweather_station_id";
static constexpr auto PWSWEATHER_API_KEY = "pwsweather_api_key";
static constexpr auto WINDGURU_STATION_UID = "windguru_station_uid";
static constexpr auto WINDGURU_STATION_PASSWORD = "windguru_station_password";
static constexpr auto WINDY_API_KEY = "windy_api_key";
static constexpr auto WINDY_STATION_ID = "windy_station_id";
static constexpr auto WU_API_KEY = "wu_api_key";
static constexpr auto WU_STATION_ID = "wu_station_id";
static constexpr auto STATION_OPTIONS_PLACEHOLDER = "station_options";
static constexpr auto SELECTED_STATION_FORM_FIELD = "station";
static constexpr auto SELECTED_STATION_PRESERVE_OPTION = "preserve settings";
static constexpr auto MQTT_HOST = "mqtt_host";
static constexpr auto MQTT_PORT = "mqtt_port";
static constexpr auto MQTT_USER = "mqtt_user";
static constexpr auto MQTT_PASS = "mqtt_pass";

void SettingsServer::startServer(fs::FS &fs, FSSettingStore &settingStore,
                                 const AvailableStationsTracker &availableStationsTracker) {
    server.on("/", HTTP_GET, [&](AsyncWebServerRequest *request) {
        request->send(fs, "/settings.html", "text/html", false, [&](const String &var) -> String {
            auto settings = settingStore.getSettings();
            if (var.equalsIgnoreCase(WIFI_SSID)) {
                return settings.getWlanSsid();
            } else if (var == WIFI_PASSWORD) {
                return settings.getWlanPassword();
            } else if (var == WIFI_AP_SSID) {
                return settings.getApSsid();
            } else if (var == WIFI_AP_PASSWORD) {
                return settings.getApPassword();
            } else if (var == TIMEZONE_STR) {
                return settings.getPosixTzString();
            } else if (var == PWSWEATHER_STATION_ID) {
                return settings.getPwsWeatherStationId();
            } else if (var == PWSWEATHER_API_KEY) {
                return settings.getPwsWeatherApiKey();
            } else if (var == WINDGURU_STATION_UID) {
                return settings.getWindGuruStationUid();
            } else if (var == WINDGURU_STATION_PASSWORD) {
                return settings.getWindGuruStationPassword();
            } else if (var == WINDY_API_KEY) {
                return settings.getWindyApiKey();
            } else if (var == WINDY_STATION_ID) {
                return settings.getWindyStationId();
            } else if (var == WU_API_KEY) {
                return settings.getWuApiKey();
            } else if (var == MQTT_HOST) {
                return settings.getMqttHost();
            } else if (var == MQTT_USER) {
                return settings.getMqttUser();
            } else if (var == MQTT_PASS) {
                return settings.getMqttPass();
            } else if (var == MQTT_PORT) {
                return settings.getMqttPort();
            } else if (var == WU_STATION_ID) {
                return settings.getWuStationId();
            } else if (var == STATION_OPTIONS_PLACEHOLDER) {
                char buf[64];
                sprintf(buf, "<option label=\"%s\">%s</option>", SELECTED_STATION_PRESERVE_OPTION,
                        SELECTED_STATION_PRESERVE_OPTION);
                String result = buf;
                for (const auto &pair: availableStationsTracker.getStations()) {
                    switch (pair.first) {
                        case StationModel::NOT_SELECTED:
                            break;
                        case StationModel::ACURITE_5N1:
                            sprintf(buf, "<option label=\"Acurite 5n1 %d\">%d</option>", pair.second, pair.second);
                            result += buf;
                            break;
                    }
                }
                return result;
            }
            return {};
        });
    });
    server.serveStatic("/", fs, "/");

    server.on("/", HTTP_POST, [&](AsyncWebServerRequest *request) {
        size_t params = request->params();
        String wlanSsid = "";
        String wlanPassword = "";
        String apSsid = "";
        String apPassword = "";
        String pwsWeatherStationId = "";
        String pwsWeatherApiKey = "";
        String windGuruStationUid = "";
        String windGuruStationPassword = "";
        String windyApiKey = "";
        String windyStationId = "";
        String wuApiKey = "";
        String wuStationId = "";
        String posixTzString = "";
        String selectedStationId = "";
        String mqttHost = "";
        String mqttPort = "";
        String mqttUser = "";
        String mqttPass = "";

        for (int i = 0; i < params; i++) {
            AsyncWebParameter *p = request->getParam(i);
            if (p->isPost()) {
                if (p->name() == WIFI_SSID) {
                    wlanSsid = p->value();
                } else if (p->name() == WIFI_PASSWORD) {
                    wlanPassword = p->value();
                } else if (p->name() == WIFI_AP_SSID) {
                    apSsid = p->value();
                } else if (p->name() == WIFI_AP_PASSWORD) {
                    apPassword = p->value();
                } else if (p->name() == TIMEZONE_STR) {
                    posixTzString = p->value();
                } else if (p->name() == PWSWEATHER_STATION_ID) {
                    pwsWeatherStationId = p->value();
                } else if (p->name() == PWSWEATHER_API_KEY) {
                    pwsWeatherApiKey = p->value();
                } else if (p->name() == WINDGURU_STATION_UID) {
                    windGuruStationUid = p->value();
                } else if (p->name() == WINDGURU_STATION_PASSWORD) {
                    windGuruStationPassword = p->value();
                } else if (p->name() == WINDY_API_KEY) {
                    windyApiKey = p->value();
                } else if (p->name() == WINDY_STATION_ID) {
                    windyStationId = p->value();
                } else if (p->name() == WU_API_KEY) {
                    wuApiKey = p->value();
                } else if (p->name() == MQTT_HOST) {
                    mqttHost = p->value();
                } else if (p->name() == MQTT_USER) {
                    mqttUser = p->value();
                } else if (p->name() == MQTT_PASS) {
                    mqttPass = p->value();
                } else if (p->name() == MQTT_PORT) {
                    mqttPort = p->value();
                } else if (p->name() == WU_STATION_ID) {
                    wuStationId = p->value();
                } else if (p->name() == SELECTED_STATION_FORM_FIELD) {
                    const String &maybeSelectedStationId = p->value();
                    if (maybeSelectedStationId == SELECTED_STATION_PRESERVE_OPTION) {
                        selectedStationId = settingStore.getSettings().getSelectedStationId();
                    } else {
                        selectedStationId = maybeSelectedStationId;
                    }
                }
            }
        }
        request->send(201, "text/html",
                      "Saving settings. The device will restart soon automatically to apply the settings.");
        Log.infoln("Applying settings update");

        WeatherBridgeSettings settings = WeatherBridgeSettings(
                std::move(wlanSsid),
                std::move(wlanPassword),
                std::move(apSsid),
                std::move(apPassword),
                std::move(posixTzString),
                std::move(pwsWeatherStationId),
                std::move(pwsWeatherApiKey),
                std::move(windGuruStationUid),
                std::move(windGuruStationPassword),
                std::move(windyApiKey),
                std::move(windyStationId),
                std::move(wuApiKey),
                std::move(wuStationId),
                std::move(selectedStationId),
                std::move(mqttHost),
                std::move(mqttUser),
                std::move(mqttPass),
                std::move(mqttPort)
        );
        settingStore.updateSettings(std::move(settings));
    });
    server.begin();
}
