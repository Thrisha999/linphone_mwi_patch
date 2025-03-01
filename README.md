# Linphone SDK - MWI (Message Waiting Indicator) Implementation

## Overview
This repository contains modifications to the Linphone SDK to enable **Message Waiting Indicator (MWI)** support.  
MWI allows SIP clients to receive **voicemail notifications** from the server using SIP **SUBSCRIBE** and **NOTIFY** messages.

## Features
- Implements **SUBSCRIBE** request for `message-summary` event.
- Handles **NOTIFY** messages for voicemail status updates.
- Modifies `linphone_proxy_config.c` to enable MWI.
- Updates `sal_eXosip2.c` to process incoming notifications.
