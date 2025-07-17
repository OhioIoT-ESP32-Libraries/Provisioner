
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
#include "html_config.h"
#include "html_instructions.h"
#include "html_success.h"


void Provisioning::_set_core_routes() {

    _web_server.on("/", [this]() { 
        Serial.println("\t.. base route hit - sending config page..");
		_send_config();
    });
    
    _web_server.on("/save", [this]() { 
        Serial.println("\t.. user clicked 'save' - storing values and continuing on..");
		strcpy(_ssid, _web_server.arg("ssid").c_str());
		strcpy(_pass, _web_server.arg("pass").c_str());


		if (!strlen(_ssid) || !strlen(_pass)) {
			Serial.println("\t.. user didn't enter enough params - sending the instruction page");
			_web_server.send(200, "text/html", INSTRUCTION_PAGE_HTML);
		} else {
			Serial.println("\t.. success getting credentials");
			_web_server.send(200, "text/html", SUCCESS_PAGE_HTML);
			// Serial.println("\n\tREBOOTING...\n\n");
			// delay(2000);
			// ESP.restart();
			_stop_provisioning();
		}
    });

}






void Provisioning::_set_extraneous_windows_routes() {

    _web_server.on("/connecttest.txt", [this]() {
        Serial.println("\t.. got 'Windows' connectivity check");
		_web_server.send(204);
    });

	_web_server.on("/time/1/current", [this]() {
        Serial.println("\t.. got 'Windows' connectivity check");
		_web_server.send(204);
    });
    
	_web_server.on("/ncsi.txt", [this]() { 
		Serial.println("\t.. got 'Windows' ncsi.txt");
		_web_server.send(204);
	 });

	_web_server.on("/redirect", [this]() { 
		Serial.println("\t.. got 'Windows' /redirect");
		_web_server.send(204);
	 });

	_web_server.on("/hotspot-detect.html", [this]() {
        Serial.println("\t.. got 'iOS' connectivity check");
		_web_server.send(204);
    });


	_web_server.on("/favicon.ico", [this]() {
		Serial.println("\t.. favicon requested");
		_web_server.send(404, "text/plain", "No favicon");
	});
		
    _web_server.onNotFound([this]() { 
        Serial.print("\txx route not found request for: ");
        Serial.println(_web_server.uri());
		_web_server.send(204);
    });
    
}





void Provisioning::_set_android_routes() {

    _web_server.on("/generate_204", [this]() {
        Serial.println("\t.. got 'Android' connectivity check");
		_send_config();
    });
    
}





void Provisioning::_set_ios_routes() {

	_web_server.on("/hotspot-detect.html", [this]() {
		Serial.println("\t.. got 'iOs' /hotspot-detect.html");
		_send_config();
	});

	_web_server.on("/library/test/success.html", [this]() {
		Serial.println("\t.. got 'iOs' /library/test/success.html");
		_send_config();
	});

	_web_server.on("/bag", [this]() {
		Serial.println("\t.. got 'iOs' /bag");
		_send_config();
	});

}


void Provisioning::_send_config() {
	_web_server.send(200, "text/html", CONFIG_PAGE_HTML);
}