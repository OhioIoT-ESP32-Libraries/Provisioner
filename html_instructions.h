#ifndef INSTRUCTION_PAGE_H
#define INSTRUCTION_PAGE_H

const char INSTRUCTION_PAGE_HTML[] PROGMEM = R"(<!DOCTYPE HTML>
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
			<h3>error!</h3>
			<div>You need to provide a value for each of the first</div>
			<div>four fields, and optionally the second two</div>
			<button onclick="window.location.href='/'">Try Again</button>
		</div>
	</body>
	</html>)";

#endif