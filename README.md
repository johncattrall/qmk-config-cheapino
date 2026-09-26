# qmk-config-cheapino

QMK keymap for the [Cheapino v2](https://github.com/tompi/cheapino), porting the
layout of my [Crosses/Bridges ZMK config](https://github.com/johncattrall/zmk-config-crosses-bridges)
to a wired 36-key board.

## What carries over

Same layer order and positions as the ZMK board: Base QWERTY and a Graphite
alternate layer (toggled from the System layer; implemented as a default-layer
swap), Nav, Media/Win with the Amethyst chords, System, and NumPad. Home row
mods use Achordion for the opposite-hands rule and typing-streak suppression
(the "timeless" feel). Same combos on the same physical positions (they resolve
against the base layer, so they work on Graphite too). Autoshift at 350 ms.
NumWord on the same thumb tap-dance: tap for a self-exiting number layer,
double-tap to lock NumPad, triple-tap to lock Nav. Graphite's custom shift
pairs (' _, , ?, . >, - ", / <) are key overrides scoped to that layer.

## What is different

No trackballs: the rotary encoder stands in, with per-layer roles wired in the
board code: wheel scroll on Base/Graphite/NumPad, Ctrl-Tab on Nav, volume on
Media, press for play/pause. No Bluetooth or soft-off (wired). The Space thumb
is a tap-dance: tap for Space, hold for F5 (dictation), which means no held-key
Space repeat, same trade as the ZMK board.

## Building

Push to this repo and CI attaches `cheapino_john.uf2` as an artifact, built
against [tompi/qmk_firmware@cheapinov2](https://github.com/tompi/qmk_firmware/tree/cheapinov2).
Flash by holding BOOTSEL while plugging in, then drag the uf2 onto the RPI-RP2
drive.

Locally: clone that tree (branch cheapinov2, and note CI patches one debounce_init call for the current QMK API), copy `keymaps/john` into `keyboards/cheapino/keymaps/`,
and run `make cheapino:john`.

## Credits

[tompi](https://github.com/tompi) (Cheapino), [getreuer](https://getreuer.info/posts/keyboards/)
(Achordion), and the layout lineage credited in the ZMK repo. Built with
[keymap-ai](https://github.com/johncattrall/keymap-ai).
