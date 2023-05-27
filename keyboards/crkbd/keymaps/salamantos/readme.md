### Flashing:
1. Connect left side, execute `qmk flash -bl avrdude-split-left`
2. Connect right side, execute `qmk flash -bl avrdude-split-right`

### Useful links
1. Handedness for split keyboard https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
2. Conversters (blok support) https://docs.qmk.fm/#/feature_converters?id=supported-converters
3. Flashing RP2040 https://github.com/qmk/qmk_firmware/blob/master/docs/flashing.md#raspberry-pi-rp2040-uf2
4. Double-tap reset boot-loader entry https://docs.qmk.fm/#/platformdev_rp2040?id=double-tap
5. Blok docs https://peg.software/docs/blok
6. RP2040 docs https://github.com/qmk/qmk_firmware/blob/master/docs/platformdev_rp2040.md
7. Corne buildguide https://github.com/foostan/crkbd/blob/main/corne-cherry/doc/v3/buildguide_en.md
8. Serial friver for communication between two halves https://docs.qmk.fm/#/serial_driver


### Flash blok with Peg:
1. Download latest release https://github.com/boardsource/bs-python (circuitpython fork)
2. In boot mode copy .uf2 to blok
3. Flash in Peg
