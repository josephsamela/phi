# Phi

This project is my first foray into building a telemetry communication system for model rockets.

The hardware is build around ESP8266 microcontrollers RFM95 radios that communicate over "LORA" 915.0Mhz. The project contains two pieces of hardware; the transmitter that rides on the launch vehicle and reciever at the ground station.

## Reciever

The reciever is built onto proto-board with a 3D printed enclosure to hang off the lid of my laptop. Connects with a USB cable and controlled via Serial. 

![](/dev-reciever.JPG)

## Transmitter
This is the dev transmitter used to build and send dummy telemetry packets. I've been using this to prototype the packet schema test reciever and integrate with other hardware (MEMS accelerometer/gyro/compass board)

![](/dev-transmitter.JPG)

## Communication Demo

Yes, I made a TikTok. It showcases my prototype communicating and I was really proud to get everything working.


<blockquote class="tiktok-embed" cite="https://www.tiktok.com/@joesamela/video/6933018332497005830" data-video-id="6933018332497005830" style="max-width: 605px;min-width: 325px;" > <section> <a target="_blank" title="@joesamela" href="https://www.tiktok.com/@joesamela">@joesamela</a> <p>Experimenting with LoRa radio! <a title="radio" target="_blank" href="https://www.tiktok.com/tag/radio">##radio</a> <a title="engineering" target="_blank" href="https://www.tiktok.com/tag/engineering">##engineering</a></p> <a target="_blank" title="♬ original sound - joesamela" href="https://www.tiktok.com/music/original-sound-6933018308660759301">♬ original sound - joesamela</a> </section> </blockquote> <script async src="https://www.tiktok.com/embed.js"></script>

