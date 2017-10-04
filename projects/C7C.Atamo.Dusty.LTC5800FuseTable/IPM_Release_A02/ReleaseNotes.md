# Release: IPM-A02

This release is simply to check if CSC can indeed flash the Dusty module. This
will use default values.

## Items

- `IPM_A02_Fuse.ini`
- `loader_1_0_6_4_oski.bin`
- `mote_ip_1_4_1_8_oski.bin`
- `mote_part_r52074.bin`

**Note** Please contact CSC for the loader, main application, and partition
table, as these _will not_ be published online.

## Flashing

``` bat
    ESP –E
    ESP –P IPM_A02_Fuse.bin 0
    ESP –P mote_part_r52074.bin 800
    ESP –P mote_ip_1_4_1_8_oski.bin 1000
    ESP –P loader_1_0_6_4_oski.bin 77800
```