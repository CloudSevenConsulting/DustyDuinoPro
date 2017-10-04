# Release: IPM-A02

This release is simply to check if CSC can indeed flash the Dusty module. This
will use default values.

This requires the initial IPM_A01 flash to be on the Dusty.

## Items

- `IPM_A02_Fuse.bin`

**Note** Please contact CSC for the loader, main application, and partition
table, as these _will not_ be published online.

## Flashing

``` bat
    ESP -P IPM_A01_Flash.bin 0
    ESP –e 0 1
    ESP –P IPM_A02_Fuse.bin 0
```
