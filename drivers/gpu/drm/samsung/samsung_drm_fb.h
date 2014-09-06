/* samsung_drm_fb.h
 *
 * Copyright (c) 2011 Samsung Electronics Co., Ltd.
 * Authors:
 *	Inki Dae <inki.dae@samsung.com>
 *	Joonyoung Shim <jy0922.shim@samsung.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * VA LINUX SYSTEMS AND/OR ITS SUPPLIERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef _SAMSUNG_DRM_FB_H_
#define _SAMSUNG_DRM_FB_H

struct samsung_drm_buffer_info {
	unsigned long paddr;
	void __iomem *vaddr;
};

int samsung_drm_fb_update_buf_off(struct drm_framebuffer *fb,
		unsigned int x, unsigned int y,
		struct samsung_drm_buffer_info *buffer_info);

struct drm_framebuffer *samsung_drm_fb_init(struct drm_file *file_priv,
		struct drm_device *dev, struct drm_mode_fb_cmd *mode_cmd);

struct drm_framebuffer *samsung_drm_fb_create(struct drm_device *dev,
		struct drm_file *file_priv, struct drm_mode_fb_cmd *mode_cmd);

#endif
