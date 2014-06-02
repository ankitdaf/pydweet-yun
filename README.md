PyDweet for Arduino Yun
=======================

A simple Python wrapper that logs sensor values to dweet.io via Arduino Yun. 

For this example, the Yun reads two sensors, and uploads them to its very own place on the Internet at dweet.io

The Arduino Sketch in this example calls the Python script to write to dweet or read from it. The Python script makes use of simple GET and POST requests from the [Dweet API](https://dweet.io/play/).

The wrapper is by no means complete, and is intended for ease of use via the Arduino Yun.