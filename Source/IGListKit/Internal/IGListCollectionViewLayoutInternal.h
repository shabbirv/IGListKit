/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

static CGRect IGListRectIntegralScaled(CGRect rect) {
    CGFloat scale;
    #if TARGET_OS_VISION
    scale =  MAX([UITraitCollection currentTraitCollection].displayScale, 1.0);
    #else
    scale = [[UIScreen mainScreen] scale];
    #endif
    return CGRectMake(floorf(rect.origin.x * scale) / scale,
                      floorf(rect.origin.y * scale) / scale,
                      ceilf(rect.size.width * scale) / scale,
                      ceilf(rect.size.height * scale) / scale);
}
