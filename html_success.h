#ifndef SUCCESS_PAGE_H
#define SUCCESS_PAGE_H

const char SUCCESS_PAGE_HTML[] PROGMEM = R"(<!DOCTYPE HTML>
	<html>
	<head>
		<meta content="text/html; charset=ISO-8859-1" http-equiv="content-type">
		<meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=0">
		<title>Device Provisioning</title>
		<style>
			body {
				background-color: white;
				font-family: Arial, sans-serif;
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
			.container {
				width: 300px;
				display: block;
				margin: 0 auto;
				text-align: center;
			}
		</style>
	</head>
	<body>
		<div class="container">
			<div id="title">
				<span>Device Provisioning</span>
			</div>
			<h3>credentials saved!</h3>
			<div>Device will restart and connect to your network</div>
		</div>
	</body>
	</html>)";


#endif