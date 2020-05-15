# WinDart Motion Sensor (Ultraschall)

Mit Ardoino R3 und Powershell Script ["nextplayer.ps1"](https://git.bawe.eu/bastian/windartoverlay/blob/master/nextplayer.ps1)

## Benörtigt wird:
 - Windart Optionsplatine
 - Ardoino R3
 - HC-SR04 Ultraschall Sensor
 - 2x EL817 Optokoppler
 - 2x Wiederstand 1K Ohm


## Event Configurator Option Panel:
 - LED9 "GameOn"  = "GameOn" im Event Configurator Option Panel
 - LED10 "L1DartRemaining" = "1DartRemaining" im Event Configurator Option Panel


## Funktion:
Der Ardoino ist über USB mit den Windart PC verbunden, und sendet über dem COM-Port Daten.
Auf dem Windart PC läuft ein Powershell Script das die Daten entgegen nimmt - und bei Bedarf ein "Enter" an Windart sendet und zum nächsten Player weiterschaltet.

**Wie beim Orginal Löwendart ist manchmal ein "winken" notwendig ;-)**

PS: Um zu erkennen, ob eine Bewegung bereits erkannt wurde, kann noch [WindartOverlay](https://git.bawe.eu/bastian/windartoverlay) verwendet werden

## Schaltung:
![Schaltung](/Schaltung.png "Schaltung")


