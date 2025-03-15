Firewall
===

Linux firewall meant for practicing cybersecurity concepts on my homelab.

The intention is to first build it in C, explore ways it may or may not be vulnerable, and then try rebuilding it in Rust.

Install For Proxmox Containers
===

- Clone this repository to the host machine.
- Add `firewall` to `/etc/modules`.
- Ensure `build-essential`, `proxmox-headers-$(uname -r)`, and `dwarves` are installed
- Copy `vmlinux` to the build folder, otherwise you'll receive a BTF generation error.
  ```
  apt install dwarves
  cp /sys/kernel/btf/vmlinux /usr/lib/modules/`uname -r`/build/
  ```
- `make` in the firewall directory, then `insmod firewall.ko` as normal


