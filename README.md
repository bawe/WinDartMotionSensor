# WinDart Motion Sensor (Ultraschall)

Mit Ardoino R3 und Powershell Script ["nextplayer.ps1"](https://git.bawe.eu/bastian/windartoverlay/blob/master/nextplayer.ps1)

|  |  |  |
| ------ | ------ | ------ |
| ![HC-SR04](/HC-SR04.jpg "HC-SR04") | ![Test des HC-SR04](/HC-SR04-test.jpg "Test des HC-SR04") | ![Anschluss](/HC-SR04-Kabel.jpg "Anschluss") |

## Funktion:
Der Ardoino ist über USB mit den Windart PC verbunden, und sendet über dem COM-Port Daten.
Auf dem Windart PC läuft ein [Powershell Script (Autostart)](https://git.bawe.eu/bastian/windartoverlay/blob/master/nextplayer.ps1) das die Daten entgegen nimmt - und bei Bedarf ein "Enter" an Windart sendet und zum nächsten Player weiterschaltet.



**Wie beim original Löwendart ist manchmal ein "winken" notwendig ;-)**

PS: Um zu erkennen, ob eine Bewegung bereits erkannt wurde, kann noch [WindartOverlay](https://git.bawe.eu/bastian/windartoverlay) verwendet werden


## Benötigt wird:
 - Windart Optionsplatine
 - Ardoino R3
 - HC-SR04 Ultraschall Sensor
 - 2x EL817 Optokoppler
 - 2x Wiederstand 1K Ohm
 - ein freier USB Port am Windart PC


## Event Configurator Option Panel:
 - LED9 "GameOn"  = "GameOn" im Event Configurator Option Panel
 - LED10 "1DartRemaining" = "1DartRemaining" im Event Configurator Option Panel


## Schaltung:
![Schaltung](/Schaltung.png "Schaltung")

### Keine Garantie für entstandene Schäden...
