#!/bin/bash
#create ad-hoc to share internet
WLAN=wlan0

#
iwconfig $WLAN mode ad-hoc
#
iwconfig $WLAN enc s:abcde [1]
iwconfig $WLAN enc open [1]

#
iwconfig $WLAN essid "lyl"

ifconfig $WLAN up

ifconfig $WLAN 169.254.1.1
#ifconfig $WLAN 192.168.1.1

echo "1" > /proc/sys/net/ipv4/ip_forward
#iptables -t nat -A POSTROUTING -o eth0 -s 192.168.1.1/24 -j MASQUERADE
iptables -t nat -A POSTROUTING -o eth0 -s 169.254.0.0/16 -j MASQUERADE
