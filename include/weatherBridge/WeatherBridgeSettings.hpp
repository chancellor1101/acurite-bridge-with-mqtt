#pragma once

#include <Arduino.h>

class WeatherBridgeSettings {
private:
    static constexpr auto DEFAULT_AP_NAME = "WBridge-AP";

    String wlanSsid = "";
    String wlanPassword = "";
    String apSsid = DEFAULT_AP_NAME;
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

public:
    WeatherBridgeSettings() = default;

    WeatherBridgeSettings(const String &&wlanSsid,
                          const String &&wlanPassword,
                          const String &&apSsid,
                          const String &&apPassword,
                          const String &&posixTzString,
                          const String &&pwsWeatherStationId,
                          const String &&pwsWeatherApiKey,
                          const String &&windGuruStationUid,
                          const String &&windGuruStationPassword,
                          const String &&windyApiKey,
                          const String &&windyStationId,
                          const String &&wuApiKey,
                          const String &&wuStationId,
                          const String &&selectedStationId,
                          const String &&mqttHost,
                          const String &&mqttPort,
                          const String &&mqttUser,
                          const String &&mqttPass
    );

    WeatherBridgeSettings(WeatherBridgeSettings &&other) noexcept;

    WeatherBridgeSettings(const WeatherBridgeSettings &other);

    WeatherBridgeSettings &operator=(WeatherBridgeSettings &&other) noexcept;

    WeatherBridgeSettings &operator=(const WeatherBridgeSettings &other) noexcept;

    const String &getWlanSsid() const;

    const String &getMqttHost() const;

    const String &getMqttPort() const;

    const String &getMqttUser() const;

    const String &getMqttPass() const;

    const String &getWlanPassword() const;

    const String &getPwsWeatherStationId() const;

    const String &getPwsWeatherApiKey() const;

    const String &getWindGuruStationUid() const;

    const String &getWindGuruStationPassword() const;

    const String &getWindyApiKey() const;

    const String &getWindyStationId() const;

    const String &getWuApiKey() const;

    const String &getWuStationId() const;

    const String &getPosixTzString() const;

    const String &getApSsid() const;

    const String &getApPassword() const;

    const String &getSelectedStationId() const;
};