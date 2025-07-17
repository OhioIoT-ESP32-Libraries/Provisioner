
// MIT License

// Copyright (c) 2025 OhioIoT, LLC

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "provisioning.h"

#include <WiFi.h>
// #include <esp_task_wdt.h> 


Provisioning::Provisioning() : _web_server(80), _provisioning_active(false) {}




void Provisioning::start() {
    _setup_access_point();
    _wait_for_completion();
}

void Provisioning::set_credentials(char *ssid, char *pass) {
    strcpy(ssid, _ssid);
	strcpy(pass, _pass);
}




void Provisioning::_setup_access_point() {

    Serial.println("\t>> entering provisioning mode...");
    
    _provisioning_active = true;
    _start_time = millis();
    
    
    WiFi.mode(WIFI_AP);

    const char* ssid = "Device Provisioning";
	WiFi.softAP(ssid);

    
    _set_core_routes();
    _set_extraneous_windows_routes();
    _set_android_routes();
    _set_ios_routes();

    _web_server.begin();
    _dns_server.start(53, "*", WiFi.softAPIP());
    
    Serial.println("\n\t***************************************************************");
	Serial.println("\t    User should:");
	Serial.print("\t        1) connect to the '");  Serial.print(ssid);  Serial.println("' network");
	Serial.print("\t        2) find the page at: ");  Serial.println(WiFi.softAPIP());
	Serial.println("\t        3) enter WiFi and MQTT credentials and click \"Submit\"");
	Serial.println("\t***************************************************************\n");
}




void Provisioning::_wait_for_completion() {
    while (_provisioning_active) {

        _dns_server.processNextRequest();
        _web_server.handleClient();
        
        if (millis() - _start_time > PROVISIONING_SERVER_TIMEOUT) {
            Serial.println("\n\txx provisioning timeout - rebooting\n");
            ESP.restart();
        }
        delay(10);
        // esp_task_wdt_reset();
    }
}


void Provisioning::_stop_provisioning() {
    Serial.println("\t.. stopping WiFi provisioning");

    _dns_server.stop();
    _web_server.stop();
    
    WiFi.softAPdisconnect(true);

    delay(2000);
    
    _provisioning_active = false;
}

