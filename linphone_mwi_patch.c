// Patch to add Message Waiting Indicator (MWI) support to Linphone 6.0 SDK

#include "linphonecore.h"

// Enable MWI subscription in SIP registration
void enable_mwi_subscription(LinphoneCore *lc) {
    LinphoneProxyConfig *proxy_cfg = linphone_core_get_default_proxy_config(lc);
    if (proxy_cfg) {
        linphone_proxy_config_enable_mwi(proxy_cfg, TRUE);
        linphone_proxy_config_set_expires(proxy_cfg, 600); // Set expiration time
        printf("MWI subscription enabled.\n");
    }
}

// Callback function to handle MWI notifications
static void message_waiting_received(LinphoneCore *lc, LinphoneProxyConfig *cfg, int messages_count) {
    if (messages_count > 0) {
        printf("You have %d new voicemail messages.\n", messages_count);
    } else {
        printf("No new voicemail messages.\n");
    }
}

// Register MWI callback function
void register_mwi_callback(LinphoneCore *lc) {
    linphone_core_set_message_received_callback(lc, message_waiting_received);
    printf("MWI callback registered.\n");
}

// Main function to integrate MWI support
void integrate_mwi_support(LinphoneCore *lc) {
    enable_mwi_subscription(lc);
    register_mwi_callback(lc);
    printf("MWI support enabled and integrated.\n");
}
