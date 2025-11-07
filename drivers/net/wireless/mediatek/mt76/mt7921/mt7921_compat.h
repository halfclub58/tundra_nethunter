/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _MT7921_COMPAT_H
#define _MT7921_COMPAT_H

#include <linux/version.h>

/* pm_runtime_resume_and_get shim */
#if LINUX_VERSION_CODE < KERNEL_VERSION(5,15,0)
static inline int pm_runtime_resume_and_get(struct device *dev)
{
	int ret = pm_runtime_get_sync(dev);
	if (ret < 0) {
		pm_runtime_put_noidle(dev);
		return ret;
	}
	return 0;
}
#endif

/* request_firmware_direct fallback */
#ifndef request_firmware_direct
#define request_firmware_direct(req, name, dev) request_firmware(req, name, dev)
#endif

/* tx status ext fallback (simplified; adjust when integrating) */
#ifndef HAVE_IEEE80211_TX_STATUS_EXT
#define mt76_tx_status_ext(hw, info) ieee80211_tx_status(hw, info->skb)
#endif

/* napi_build_skb fallback */
#ifndef HAVE_NAPI_BUILD_SKB
#define napi_build_skb(data, frag_len) build_skb(data, frag_len)
#endif

#endif /* _MT7921_COMPAT_H */