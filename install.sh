#!/bin/bash

mkdir -p /etc/custom_firewall/
cp ./default.rules /etc/custom_firewall/default.rules
cp ./accept-all.rules /etc/custom_firewall/accept-all.rules
cp /etc/custom_firewall/default.rules /etc/custom_firewall/current.rules
