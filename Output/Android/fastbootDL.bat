adb wait-for-device reboot bootloader
fastboot oem unlock
fastboot format userdata
fastboot -w
fastboot flash bootloader %1\bootloader.img
fastboot flash boot %1\boot.img
fastboot flash system %1\system.img
fastboot reboot
pause