#include "weatherBridge/WeatherBridgeSettings.hpp"

WeatherBridgeSettings::WeatherBridgeSettings(
        const String &&wlanSsid,
        const String &&wlanPassword,
        const String &&apSsid,
        const String &&apPassword,
        const String &&posixTzString,
        const String &&pwsWeatherStationId,
        const String &&pwsWeatherApiKey,
        const String &&windGuruStationUid,
        const String &&windGuruStationPwd,
        const String &&windyApiKey,
        const String &&windyStationId,
        const String &&wuApiKey,
        const String &&wuStationId,
        const String &&selectedStationId,
        const String &&mqttHost,
        const String &&mqttUser,
        const String &&mqttPass,
        const String &&mqttPort
) : wlanSsid(wlanSsid),
    wlanPassword(wlanPassword),
    apSsid(apSsid.isEmpty() ? String(DEFAULT_AP_NAME) : apSsid),
    apPassword(apPassword),
    posixTzString(posixTzString),
    pwsWeatherStationId(pwsWeatherStationId),
    pwsWeatherApiKey(pwsWeatherApiKey),
    windGuruStationUid(windGuruStationUid),
    windGuruStationPassword(windGuruStationPwd),
    windyApiKey(windyApiKey),
    windyStationId(windyStationId),
    wuApiKey(wuApiKey),
    wuStationId(wuStationId),
    selectedStationId(selectedStationId),
    mqttHost(mqttHost),
    mqttUser(mqttUser),
    mqttPass(mqttPass),
    mqttPort(mqttPort) {}


WeatherBridgeSettings::WeatherBridgeSettings(WeatherBridgeSettings &&other) noexcept:
        wlanSsid(std::move(other.wlanSsid)),
        wlanPassword(std::move(other.wlanPassword)),
        apSsid(std::move(other.apSsid)),
        apPassword(std::move(other.apPassword)),
        posixTzString(std::move(other.posixTzString)),
        pwsWeatherStationId(std::move(other.pwsWeatherStationId)),
        pwsWeatherApiKey(std::move(other.pwsWeatherApiKey)),
        windGuruStationUid(std::move(other.windGuruStationUid)),
        windGuruStationPassword(std::move(other.windGuruStationPassword)),
        windyApiKey(std::move(other.windyApiKey)),
        windyStationId(std::move(other.windyStationId)),
        wuApiKey(std::move(other.wuApiKey)),
        wuStationId(std::move(other.wuStationId)),
        selectedStationId(std::move(other.selectedStationId)),
        mqttHost(std::move(other.mqttHost)),
        mqttPort(std::move(other.mqttPort)),
        mqttUser(std::move(other.mqttUser)),
        mqttPass(std::move(other.mqttPass)) {}

WeatherBridgeSettings::WeatherBridgeSettings(const WeatherBridgeSettings &other) = default;

WeatherBridgeSettings &WeatherBridgeSettings::operator=(WeatherBridgeSettings &&other) noexcept {
    if (this != &other) {
        wlanSsid = std::move(other.wlanSsid);
        wlanPassword = std::move(other.wlanPassword);
        apSsid = std::move(other.apSsid);
        apPassword = std::move(other.apPassword);
        posixTzString = std::move(other.posixTzString);
        pwsWeatherStationId = std::move(other.pwsWeatherStationId);
        pwsWeatherApiKey = std::move(other.pwsWeatherApiKey);
        windGuruStationUid = std::move(other.windGuruStationUid);
        windGuruStationPassword = std::move(other.windGuruStationPassword);
        windyApiKey = std::move(other.windyApiKey);
        windyStationId = std::move(other.windyStationId);
        wuApiKey = std::move(other.wuApiKey);
        wuStationId = std::move(other.wuStationId);
        selectedStationId = std::move(other.selectedStationId);
        mqttHost = std::move(other.mqttHost);
        mqttPort = std::move(other.mqttPort);
        mqttUser = std::move(other.mqttUser);
        mqttPass = std::move(other.mqttPass);
    }
    return *this;
}

WeatherBridgeSettings &WeatherBridgeSettings::operator=(const WeatherBridgeSettings &other) noexcept {
    if (this != &other) {
        wlanSsid = other.wlanSsid;
        wlanPassword = other.wlanPassword;
        apSsid = other.apSsid;
        apPassword = other.apPassword;
        posixTzString = other.posixTzString;
        pwsWeatherStationId = other.pwsWeatherStationId;
        pwsWeatherApiKey = other.pwsWeatherApiKey;
        windGuruStationUid = other.windGuruStationUid;
        windGuruStationPassword = other.windGuruStationPassword;
        windyApiKey = other.windyApiKey;
        windyStationId = other.windyStationId;
        wuApiKey = other.wuApiKey;
        wuStationId = other.wuStationId;
        selectedStationId = other.selectedStationId;
        mqttHost = other.mqttHost;
        mqttPort = other.mqttPort;
        mqttUser = other.mqttUser;
        mqttPass = other.mqttPass;
    }
    return *this;
}

const String &WeatherBridgeSettings::getMqttHost() const {
    return mqttHost;
}

const String &WeatherBridgeSettings::getMqttPort() const {
    return mqttPort;
}

const String &WeatherBridgeSettings::getMqttUser() const {
    return mqttUser;
}

const String &WeatherBridgeSettings::getMqttPass() const {
    return mqttPass;
}

const String &WeatherBridgeSettings::getWlanSsid() const {
    return wlanSsid;
}

const String &WeatherBridgeSettings::getWlanPassword() const {
    return wlanPassword;
}

const String &WeatherBridgeSettings::getApSsid() const {
    return apSsid;
}

const String &WeatherBridgeSettings::getApPassword() const {
    return apPassword;
}

const String &WeatherBridgeSettings::getPwsWeatherStationId() const {
    return pwsWeatherStationId;
}

const String &WeatherBridgeSettings::getPwsWeatherApiKey() const {
    return pwsWeatherApiKey;
}

const String &WeatherBridgeSettings::getWindGuruStationUid() const {
    return windGuruStationUid;
}

const String &WeatherBridgeSettings::getWindGuruStationPassword() const {
    return windGuruStationPassword;
}

const String &WeatherBridgeSettings::getWindyApiKey() const {
    return windyApiKey;
}

const String &WeatherBridgeSettings::getWindyStationId() const {
    return windyStationId;
}

const String &WeatherBridgeSettings::getWuApiKey() const {
    return wuApiKey;
}

const String &WeatherBridgeSettings::getWuStationId() const {
    return wuStationId;
}

const String &WeatherBridgeSettings::getPosixTzString() const {
    return posixTzString;
}

const String &WeatherBridgeSettings::getSelectedStationId() const {
    return selectedStationId;
}
