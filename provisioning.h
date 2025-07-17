
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

#ifndef PROVISIONING_H
#define PROVISIONING_H

#include "Arduino.h"
#include <WebServer.h>
#include <DNSServer.h>

#define PROVISIONING_SERVER_TIMEOUT 300000



class Provisioning {

	public:

		Provisioning();

		void start();
		void set_credentials(char *, char *);

	private:
	
		WebServer _web_server;
		DNSServer _dns_server;
		bool _provisioning_active;
		unsigned long _start_time;

		char _ssid[32];
		char _pass[32];
		
		// provisioning.cpp
		void _setup_access_point();
		void _wait_for_completion();
		void _stop_provisioning();

		// provisioning_routes.cpp
		void _set_core_routes();
		void _set_extraneous_windows_routes();
		void _set_android_routes();
		void _set_ios_routes();

		void _send_config();

		

};

extern Provisioning provisioning;	// call "Provisioner provisioner" once in main.cpp

#endif