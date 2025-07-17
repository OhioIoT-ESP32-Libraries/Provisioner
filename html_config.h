#ifndef CONFIG_PAGE_H
#define CONFIG_PAGE_H

const char CONFIG_PAGE_HTML[] PROGMEM = R"(<!DOCTYPE HTML>
<html>
<head>
    <meta content="text/html; charset=ISO-8859-1" http-equiv="content-type">
    <meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=0">
    <title>Device Provisioning</title>
    <style>
        body {
            background-color: white;
            font-family: Arial, sans-serif;
            box-sizing: border-box;
        }
        #title {
            margin: 50px 0;
            font-size: 24px;
            font-weight: bold; 
        }
        span {
            margin: 0;
            display: inline-block;
        }
        input {
            width: 220px;
            padding: 5px 10px;
            margin: 4px auto 24px;
            border: 1px solid #aaa;
            border-radius: 4px;
        }
        input[type="submit"] {
            width: 100px;
            border-radius: 8px;
            background-color: #ddd;
            border: 1px solid #aaa;
            padding: 10px 20px;
            text-align: center;
            // text-decoration: none;
            display: inline-block;
            font-size: 16px;
            margin-top: 50px;
        }
        .container {
            width: 300px;
            margin: 0 auto;
            text-align: center;
        }
        form > div {
            width: 220px;
            text-align: left;
        }
    </style>
</head>
<body>
    <div class="container">
        <div id="title">
            <span>Device Provisioning</span>
        </div>
        <form action="/save" method="post">

            <div>SSID:</div>
            <input maxlength="30" type="text" id="wifi_ssid" name="ssid" placeholder="Enter WiFi SSID" required><br>
          
            <div>WiFi Password:</div>
            <input maxlength="30" type="password" id="wifi_pass" name="pass" placeholder="Enter WiFi PASSKEY"><br>
                       
            <input type="submit" value="Save">
        </form>
    </div>
</body>
</html>)";

#endif