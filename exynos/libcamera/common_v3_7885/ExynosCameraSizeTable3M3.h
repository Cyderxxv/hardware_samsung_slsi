/*
**
** Copyright 2013, Samsung Electronics Co. LTD
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#ifndef EXYNOS_CAMERA_LUT_3M3_H
#define EXYNOS_CAMERA_LUT_3M3_H

#include "ExynosCameraConfig.h"

/* -------------------------
    SIZE_RATIO_16_9 = 0,
    SIZE_RATIO_4_3,
    SIZE_RATIO_1_1,
    SIZE_RATIO_3_2,
    SIZE_RATIO_5_4,
    SIZE_RATIO_5_3,
    SIZE_RATIO_11_9,
    SIZE_RATIO_END
----------------------------
    RATIO_ID,
    SENSOR_W   = 1,
    SENSOR_H,
    BNS_W,
    BNS_H,
    BCROP_W,
    BCROP_H,
    BDS_W,
    BDS_H,
    TARGET_W,
    TARGET_H,
-----------------------------
    Sensor Margin Width  = 0,
    Sensor Margin Height = 0
-----------------------------*/

static int PREVIEW_SIZE_LUT_3M3[][SIZE_OF_LUT] =
{
    /* Binning   = OFF
       BNS ratio = 1.0
       BDS       = 1440p */

    /* 16:9 (Single, Dual) */
    { SIZE_RATIO_16_9,
     (4032 + 0) ,(2268 + 0),   /* [sensor ] */
      4032      , 2268      ,   /* [bns    ] */
      4032      , 2268      ,   /* [bcrop  ] */
      2688      , 1512      ,   /* [bds    ] */
      1920      , 1080      ,   /* [target ] */
    },
    /* 4:3 (Single, Dual) */
    { SIZE_RATIO_4_3,
     (4032 + 0) ,(3024 + 0),   /* [sensor ] */
      4032      , 3024      ,   /* [bns    ] */
      4032      , 3024      ,   /* [bcrop  ] */
      2688      , 2016      ,   /* [bds    ] */
      1440      , 1080      ,   /* [target ] */
    },
    /* 1:1 (Single, Dual) */
    { SIZE_RATIO_1_1,
     (3024 + 0),(3024 + 0),   /* [sensor ] */
      3024      , 3024      ,   /* [bns    ] */
      3024      , 3024      ,   /* [bcrop  ] */
      2016      , 2016      ,   /* [bds    ] */
      1080      , 1080      ,   /* [target ] */
    },
    /* 3:2 (Single, Dual) */
    { SIZE_RATIO_3_2,
     (4032 + 0) ,(3024 + 0) ,   /* [sensor ] */
      4032      , 3024      ,   /* [bns    ] */
      4032      , 2688      ,   /* [bcrop  ] */
      2688      , 1792      ,   /* [bds    ] */
      1616      , 1080      ,   /* [target ] */
    },
    /* 5:4 (Single, Dual) */
    { SIZE_RATIO_5_4,
     (4032 + 0) ,(3024 + 0) ,   /* [sensor ] */
      4032      , 3024      ,   /* [bns    ] */
      3780      , 3024      ,   /* [bcrop  ] */
      2480      , 1984      ,   /* [bds    ] */
      1344      , 1080      ,   /* [target ] */
    },
    /* 5:3 (Single, Dual) */
    { SIZE_RATIO_5_3,
     (4032 + 0) ,(3024 + 0) ,   /* [sensor ] */
      4032      , 3024      ,   /* [bns    ] */
      4030      , 2418      ,   /* [bcrop  ] */
      2640      , 1584      ,   /* [bds    ] */
      1792      , 1080      ,   /* [target ] */
    },
    /* 11:9 (Single, Dual) */
    { SIZE_RATIO_11_9,
     (4032 + 0) ,(3024 + 0) ,   /* [sensor ] */
      4032      , 3024      ,   /* [bns    ] */
      3696      , 3024      ,   /* [bcrop  ] */
      2464      , 2016      ,   /* [bds    ] */
      1312      , 1080      ,   /* [target ] */
    },
    /* Dummy (not used) */
    { SIZE_RATIO_9_16,
     (4032 + 0) ,(3024 + 0) ,   /* [sensor ] */
      4032      , 3024      ,   /* [bns    ] */
      3696      , 3024      ,   /* [bcrop  ] */
      2464      , 2016      ,   /* [bds    ] */
      1312      , 1080      ,   /* [target ] */
    },
    /* 18.5:9 (Single, Dual) */
    { SIZE_RATIO_18P5_9,
     (4032 + 0) ,(1960 + 0) ,   /* [sensor ] */
      4032      , 1960      ,   /* [bns    ] */
      4032      , 1960      ,   /* [bcrop  ] */
      2688      , 1306      ,   /* [bds    ] */
      2224      , 1080      ,   /* [target ] */
    }
};

static int PREVIEW_SIZE_LUT_3M3_BNS[][SIZE_OF_LUT] =
{
    /* Binning   = OFF
       BNS ratio = 1.5
       BDS       = 1440p */

    /* 16:9 (Single, Dual) */
    { SIZE_RATIO_16_9,
     (4032 + 0) ,(2268 + 0),   /* [sensor ] */
      2688      , 1512      ,   /* [bns    ] */
      2688      , 1512      ,   /* [bcrop  ] */
      2688      , 1512      ,   /* [bds    ] */
      1920      , 1080      ,   /* [target ] */
    },
    /* 4:3 (Single, Dual) */
    { SIZE_RATIO_4_3,
     (4032 + 0) ,(3024 + 0),   /* [sensor ] */
      2688      , 2016      ,   /* [bns    ] */
      2688      , 2016      ,   /* [bcrop  ] */
      2688      , 2016      ,   /* [bds    ] */
      1440      , 1080      ,   /* [target ] */
    },
    /* 1:1 (Single, Dual) */
    { SIZE_RATIO_1_1,
     (4032 + 0),(3024 + 0),   /* [sensor ] */
      2688      , 2016      ,   /* [bns    ] */
      2688      , 2016      ,   /* [bcrop  ] */
      2688      , 2016      ,   /* [bds    ] */
      1080      , 1080      ,   /* [target ] */
    },
    /* 3:2 (Single, Dual) */
    { SIZE_RATIO_3_2,
     (4032 + 0) ,(3024 + 0) ,   /* [sensor ] */
      2688      , 1356      ,   /* [bns    ] */
      2688      , 1356      ,   /* [bcrop  ] */
      2688      , 1356      ,   /* [bds    ] */
      1616      , 1080      ,   /* [target ] */
    },
    /* 5:4 (Single, Dual) */
    { SIZE_RATIO_5_4,
     (4032 + 0) ,(3024 + 0) ,   /* [sensor ] */
      2688      , 1356      ,   /* [bns    ] */
      2530      , 1356      ,   /* [bcrop  ] */
      2530      , 1356      ,   /* [bds    ] */
      1344      , 1080      ,   /* [target ] */
    },
    /* 5:3 (Single, Dual) */
    { SIZE_RATIO_5_3,
     (4032 + 0) ,(3024 + 0) ,   /* [sensor ] */
      2688      , 1356      ,   /* [bns    ] */
      2688      , 1612      ,   /* [bcrop  ] */
      2688      , 1612      ,   /* [bds    ] */
      1792      , 1080      ,   /* [target ] */
    },
    /* 11:9 (Single, Dual) */
    { SIZE_RATIO_11_9,
     (4032 + 0) ,(3024 + 0) ,   /* [sensor ] */
      2688      , 1356      ,   /* [bns    ] */
      2464      , 1356      ,   /* [bcrop  ] */
      2464      , 1356      ,   /* [bds    ] */
      1312      , 1080      ,   /* [target ] */
    },
    /* Dummy (not used) */
    { SIZE_RATIO_9_16,
     (4032 + 0) ,(3024 + 0) ,   /* [sensor ] */
      4032      , 3024      ,   /* [bns    ] */
      3696      , 3024      ,   /* [bcrop  ] */
      2464      , 2016      ,   /* [bds    ] */
      1312      , 1080      ,   /* [target ] */
    },
    /* 18.5:9 (Single, Dual) */
    { SIZE_RATIO_18P5_9,
     (4032 + 0), (1960 + 0) ,   /* [sensor ] */
      2688      , 1306      ,   /* [bns    ] */
      2688      , 1306      ,   /* [bcrop  ] */
      2688      , 1306      ,   /* [bds    ] */
      2224      , 1080      ,   /* [target ] */
    }
};

static int PICTURE_SIZE_LUT_3M3[][SIZE_OF_LUT] =
{
    /* Binning   = OFF
       BNS ratio = 1.0
       BDS       = OFF */

    /* 16:9 (Single, Dual) */
    { SIZE_RATIO_16_9,
     (4032 + 0),(2268 + 0),   /* [sensor ] */
      4032      , 2268      ,   /* [bns    ] */
      4032      , 2268      ,   /* [bcrop  ] */
      4032      , 2268      ,   /* [bds    ] */
      4032      , 2268      ,   /* [target ] */
    },
    /* 4:3 (Single, Dual) */
    { SIZE_RATIO_4_3,
     (4032 + 0),(3024 + 0),   /* [sensor ] */
      4032      , 3024      ,   /* [bns    ] */
      4032      , 3024      ,   /* [bcrop  ] */
      4032      , 3024      ,   /* [bds    ] */
      4032      , 3024      ,   /* [target ] */
    },
    /* 1:1 (Single, Dual) */
    { SIZE_RATIO_1_1,
     (3024 + 0),(3024 + 0),   /* [sensor ] */
      3024      , 3024      ,   /* [bns    ] */
      3024      , 3024      ,   /* [bcrop  ] */
      3024      , 3024      ,   /* [bds    ] */
      3024      , 3024      ,   /* [target ] */
    },
    /* 18.5:9 (Single, Dual) */
    { SIZE_RATIO_18P5_9,
     (4032 + 0), (1960 + 0) ,   /* [sensor ] */
      4032      , 1960      ,   /* [bns    ] */
      4032      , 1960      ,   /* [bcrop  ] */
      4032      , 1960      ,   /* [bds    ] */
      4032      , 1960      ,   /* [target ] */
    }
};

static int VIDEO_SIZE_LUT_3M3[][SIZE_OF_LUT] =
{
    /* Binning   = OFF
       BNS ratio = 1.0
       BDS       = 1080p */

    /* 16:9 (Single) */
    { SIZE_RATIO_16_9,
     (4032 + 0) ,(2268 + 0) ,   /* [sensor ] */
      4032      , 2268      ,   /* [bns    ] */
      4032      , 2268      ,   /* [bcrop  ] */
      2688      , 1512      ,   /* [bds    ] *//* UHD (3840x2160) special handling in ExynosCameraParameters class */
      1920      , 1080      ,   /* [target ] */
    },
    /* 4:3 (Single) */
    { SIZE_RATIO_4_3,
     (4032 + 0) ,(3024 + 0) ,   /* [sensor ] */
      4032      , 3024      ,   /* [bns    ] */
      4032      , 3024      ,   /* [bcrop  ] */
      2688      , 2016      ,   /* [bds    ] */
      1440      , 1080      ,   /* [target ] */
    },
    /* 1:1 (Single, Dual) */
    { SIZE_RATIO_1_1,
     (3024 + 0) ,(3024 + 0) ,   /* [sensor ] */
      3024      , 3024      ,   /* [bns    ] */
      3024      , 3024      ,   /* [bcrop  ] */
      2016      , 2016      ,   /* [bds    ] */
      1080      , 1080      ,   /* [target ] */
    },
    /* 3:2 (Single) */
    { SIZE_RATIO_3_2,
     (4032 + 0) ,(3024 + 0) ,   /* [sensor ] */
      4032      , 3024      ,   /* [bns    ] */
      4032      , 2688      ,   /* [bcrop  ] */
      2688      , 1792      ,   /* [bds    ] */
      1616      , 1080      ,   /* [target ] */
    },
    /* 5:4 (Single) */
    { SIZE_RATIO_5_4,
     (4032 + 0) ,(3024 + 0) ,   /* [sensor ] */
      4032      , 3024      ,   /* [bns    ] */
      3780      , 3024      ,   /* [bcrop  ] */
      2480      , 1984      ,   /* [bds    ] */
      1344      , 1080      ,   /* [target ] */
    },
    /* 5:3 (Single) */
    { SIZE_RATIO_5_3,
     (4032 + 0) ,(3024 + 0) ,   /* [sensor ] */
      4032      , 3024      ,   /* [bns    ] */
      4030      , 2418      ,   /* [bcrop  ] */
      2640      , 1584      ,   /* [bds    ] */
      1792      , 1080      ,   /* [target ] */
    },
    /* 11:9 (Single) */
    { SIZE_RATIO_11_9,
     (4032 + 0) ,(3024 + 0) ,   /* [sensor ] */
      4032      , 3024      ,   /* [bns    ] */
      3696      , 3024      ,   /* [bcrop  ] */
      2464      , 2016      ,   /* [bds    ] */
      1312      , 1080      ,   /* [target ] */
    }
};

static int VIDEO_SIZE_LUT_3M3_BNS[][SIZE_OF_LUT] =
{
    /* Binning   = OFF
       BNS ratio = 1.5
       BDS       = 1080p */

    /* 16:9 (Single) */
    { SIZE_RATIO_16_9,
     (4032 + 0) ,(2268 + 0) ,   /* [sensor ] */
      2688      , 1512      ,   /* [bns    ] */
      2688      , 1512      ,   /* [bcrop  ] */
      2688      , 1512      ,   /* [bds    ] *//* UHD (3840x2160) special handling in ExynosCameraParameters class */
      1920      , 1080      ,   /* [target ] */
    },
    /* 4:3 (Single) */
    { SIZE_RATIO_4_3,
     (4032 + 0) ,(3024 + 0) ,   /* [sensor ] */
      2688      , 2016      ,   /* [bns    ] */
      2688      , 2016      ,   /* [bcrop  ] */
      2688      , 2016      ,   /* [bds    ] */
      1440      , 1080      ,   /* [target ] */
    },
    /* 1:1 (Single, Dual) */
    { SIZE_RATIO_1_1,
     (4032 + 0) ,(3024 + 0) ,   /* [sensor ] */
      2688      , 2016      ,   /* [bns    ] */
      2688      , 2016      ,   /* [bcrop  ] */
      2688      , 2016      ,   /* [bds    ] */
      1080      , 1080      ,   /* [target ] */
    },
};

static int VIDEO_SIZE_LUT_60FPS_HIGH_SPEED_3M3[][SIZE_OF_LUT] =
{
    /* Binning   = ON
       BNS ratio = 1.0
       BDS       = ON */

    /* FHD_60 16:9 (Single) */
    { SIZE_RATIO_16_9,
     (1920 + 0)  ,(1080 + 0) ,   /* [sensor ] */
      1920       , 1080      ,   /* [bns    ] */
      1920       , 1080      ,   /* [bcrop  ] */
      1920       , 1080      ,   /* [bds    ] */
      1920      ,  1080      ,   /* [target ] */
    },
};

static int VIDEO_SIZE_LUT_120FPS_HIGH_SPEED_3M3[][SIZE_OF_LUT] =
{
    /* Binning   = ON
       BNS ratio = 1.0
       BDS       = ON */

    /* HD_120 16:9 (Single) */
    { SIZE_RATIO_16_9,
     (1376 + 0)  ,(774 + 0) ,   /* [sensor ] */
      1376       , 774      ,   /* [bns    ] */
      1376       , 774      ,   /* [bcrop  ] */
      1376       , 774      ,   /* [bds    ] */
      1280      ,  720      ,   /* [target ] */
    },
};

static int VTCALL_SIZE_LUT_3M3[][SIZE_OF_LUT] =
{
    /* Binning   = 2
       BNS ratio = 1.0
       BDS       = ON */

    /* 16:9 (VT_Call) */
    { SIZE_RATIO_16_9,
     (2016 + 0) ,(1134 + 0) ,   /* [sensor ] */
      2016      , 1134      ,   /* [bns    ] */
      2016      , 1134      ,   /* [bcrop  ] */
      2016      , 1134      ,   /* [bds    ] */
      1920      , 1080      ,   /* [target ] */
    },
    /* 4:3 (VT_Call) */
    { SIZE_RATIO_4_3,
     (2016 + 0) ,(1512 + 0) ,   /* [sensor ] */
      2016      , 1512      ,   /* [bns    ] */
      2016      , 1512      ,   /* [bcrop  ] */
      2016      , 1512      ,   /* [bds    ] */
       640      ,  480      ,   /* [target ] */
    },
    /* 1:1 (VT_Call) */
    { SIZE_RATIO_1_1,
     (1504 + 0) ,(1504 + 0) ,   /* [sensor ] */
      1504      , 1504      ,   /* [bns    ] */
      1504      , 1504      ,   /* [bcrop  ] */
      1504      , 1504      ,   /* [bds    ] */
      1080      , 1080      ,   /* [target ] */
    },
    /* 3:2 (VT_Call) */
    { SIZE_RATIO_3_2,
     (2016 + 0) ,(1134 + 0) ,   /* [sensor ] */
      2016      , 1134      ,   /* [bns    ] */
      1680      , 1120      ,   /* [bcrop  ] */
      1680      , 1120      ,   /* [bds    ] */
      1616      , 1080      ,   /* [target ] */
    },
    /* 11:9 (VT_Call) */
    { SIZE_RATIO_11_9,
     (2016 + 0) ,(1134 + 0) ,   /* [sensor ] */
      2016      , 1134      ,   /* [bns    ] */
      1232      , 1008      ,   /* [bcrop  ] */
      1232      , 1008      ,   /* [bds    ] */
      1232      , 1008      ,   /* [target ] */
    }
};

static int LIVE_BROADCAST_SIZE_LUT_3M3[][SIZE_OF_LUT] =
{
    /* Binning   = 2
       BNS ratio = 1.0
       BDS       = ON */

    /* 16:9 */
    { SIZE_RATIO_16_9,
     (2016 + 0) ,(1134 + 0) ,   /* [sensor ] */
      2016      , 1134      ,   /* [bns    ] */
      2016      , 1134      ,   /* [bcrop  ] */
      2016      , 1134      ,   /* [bds    ] */
      1920      , 1080      ,   /* [target ] */
    },
    /* 4:3 */
    { SIZE_RATIO_4_3,
     (2016 + 0) ,(1512 + 0) ,   /* [sensor ] */
      2016      , 1512      ,   /* [bns    ] */
      2016      , 1512      ,   /* [bcrop  ] */
      2016      , 1512      ,   /* [bds    ] */
      1440      , 1080      ,   /* [target ] */
    },
    /* 1:1 */
    { SIZE_RATIO_1_1,
     (1504 + 0) ,(1504 + 0) ,   /* [sensor ] */
      1504      , 1504      ,   /* [bns    ] */
      1504      , 1504      ,   /* [bcrop  ] */
      1504      , 1504      ,   /* [bds    ] */
      1080      , 1080      ,   /* [target ] */
    },

    /* 11:9 */
    { SIZE_RATIO_11_9,
     (2016 + 0) ,(1134 + 0),   /* [sensor ] */
      2016      , 1134      ,	/* [bns    ] */
      1232      , 1008      ,	/* [bcrop  ] */
      1232      , 1008      ,	/* [bds    ] */
      1232      , 1008      ,	/* [target ] */
    },
};

static int FAST_AE_STABLE_SIZE_LUT_3M3[][SIZE_OF_LUT] =
{
    /* Binning   = ON
       BNS ratio = 4.0 / FPS = 120
       BDS       = ON */

    /* FAST_AE 16:9 (Single) */
    { SIZE_RATIO_16_9,
     (1344 + 0) , (756 + 0) ,   /* [sensor ] */
      1344      ,  756      ,   /* [bns    ] */
      1344      ,  756      ,   /* [bcrop  ] */
      1344      ,  756      ,   /* [bds    ] */
      1280      ,  720      ,   /* [target ] */
    },
};

static int YUV_SIZE_LUT_3M3[][SIZE_OF_LUT] =
{
    /* Binning   = OFF
       BNS ratio = 1.0
       BDS       = 1080p */

    /* 16:9 (Single) */
    { SIZE_RATIO_16_9,
     (4032 + 0) ,(3024 + 0) ,   /* [sensor ] */
      4032      , 3024      ,   /* [bns    ] */
      4032      , 3024      ,   /* [bcrop  ] */
      4032      , 3024      ,   /* [bds    ] *//* UHD (3840x2160) special handling in ExynosCameraParameters class */
      4032      , 3024      ,   /* [target ] */
    },
    /* 4:3 (Single) */
    { SIZE_RATIO_4_3,
     (4032 + 0) ,(3024 + 0) ,   /* [sensor ] */
      4032      , 3024      ,   /* [bns    ] */
      4032      , 3024      ,   /* [bcrop  ] */
      4032      , 3024      ,   /* [bds    ] */
      4032      , 3024      ,   /* [target ] */
    },
    /* 1:1 (Single, Dual) */
    { SIZE_RATIO_1_1,
     (4032 + 0) ,(3024 + 0) ,   /* [sensor ] */
      4032      , 3024      ,   /* [bns    ] */
      4032      , 3024      ,   /* [bcrop  ] */
      4032      , 3024      ,   /* [bds    ] */
      4032      , 3024      ,   /* [target ] */
    },
    /* 3:2 (Single) */
    { SIZE_RATIO_3_2,
     (4032 + 0) ,(3024 + 0) ,   /* [sensor ] */
      4032      , 3024      ,   /* [bns    ] */
      4032      , 3024      ,   /* [bcrop  ] */
      4032      , 3024      ,   /* [bds    ] */
      4032      , 3024      ,   /* [target ] */
    },
    /* 5:4 (Single) */
    { SIZE_RATIO_5_4,
     (4032 + 0) ,(3024 + 0) ,   /* [sensor ] */
      4032      , 3024      ,   /* [bns    ] */
      4032      , 3024      ,   /* [bcrop  ] */
      4032      , 3024      ,   /* [bds    ] */
      4032      , 3024      ,   /* [target ] */
    },
    /* 5:3 (Single) */
    { SIZE_RATIO_5_3,
     (4032 + 0) ,(3024 + 0) ,   /* [sensor ] */
      4032      , 3024      ,   /* [bns    ] */
      4032      , 3024      ,   /* [bcrop  ] */
      4032      , 3024      ,   /* [bds    ] */
      4032      , 3024      ,   /* [target ] */
    },
    /* 11:9 (Single) */
    { SIZE_RATIO_11_9,
     (4032 + 0) ,(3024 + 0) ,   /* [sensor ] */
      4032      , 3024      ,   /* [bns    ] */
      4032      , 3024      ,   /* [bcrop  ] */
      4032      , 3024      ,   /* [bds    ] */
      4032      , 3024      ,   /* [target ] */
    },
    /* Dummy (not used) */
    { SIZE_RATIO_9_16,
     (4032 + 0) ,(3024 + 0) ,   /* [sensor ] */
      4032      , 3024      ,   /* [bns    ] */
      4032      , 3024      ,   /* [bcrop  ] */
      4032      , 3024      ,   /* [bds    ] */
      4032      , 3024      ,   /* [target ] */
    },
    /* 18.5:9 (Single) */
    { SIZE_RATIO_18P5_9,
     (4032 + 0) ,(3024 + 0) ,   /* [sensor ] */
      4032      , 3024      ,   /* [bns    ] */
      4032      , 3024      ,   /* [bcrop  ] */
      4032      , 3024      ,   /* [bds    ] */
      4032      , 3024      ,   /* [target ] */
    }
};

static int DEPTH_MAP_SIZE_LUT_3M3[][SIZE_OF_RESOLUTION] =
{
    { SIZE_RATIO_16_9,
        504      ,  282      ,   /* [vci    ] */
    },
    { SIZE_RATIO_4_3,
        504      ,  378      ,   /* [vci    ] */
    },
    { SIZE_RATIO_1_1,
        376      ,  376      ,   /* [vci    ] */
    },
    { SIZE_RATIO_3_2,
        504      ,  378      ,   /* [vci    ] */
    },
    { SIZE_RATIO_5_4,
        504      ,  378      ,   /* [vci    ] */
    },
    { SIZE_RATIO_5_3,
        504      ,  378      ,   /* [vci    ] */
    },
    { SIZE_RATIO_11_9,
        504      ,  378      ,   /* [vci    ] */
    },
    { SIZE_RATIO_9_16,
        504      ,  378      ,   /* dummy */
    },
    { SIZE_RATIO_18P5_9,
        504      ,  244      ,   /* [vci    ] */
    }
};

static int S5K3M3_PREVIEW_LIST[][SIZE_OF_RESOLUTION] =
{
#if defined(LIMIT_SCP_SIZE_UNTIL_FHD_ON_CAPTURE)
#else
    { 2560, 1440, SIZE_RATIO_16_9},
    { 1920, 1440, SIZE_RATIO_4_3},
    { 1440, 1440, SIZE_RATIO_1_1},
#endif
#if defined(CAMERA_LCD_SIZE) && (CAMERA_LCD_SIZE >= LCD_SIZE_1920_1080)
    { 1920, 1080, SIZE_RATIO_16_9},
    { 1440, 1080, SIZE_RATIO_4_3},
    { 1088, 1088, SIZE_RATIO_1_1},
#endif
    { 1280,  720, SIZE_RATIO_16_9},
    { 1056,  704, SIZE_RATIO_3_2},
    { 1024,  768, SIZE_RATIO_4_3},
    {  960,  720, SIZE_RATIO_4_3},
    {  800,  450, SIZE_RATIO_16_9},
    {  720,  720, SIZE_RATIO_1_1},
    {  720,  480, SIZE_RATIO_3_2},
    {  640,  480, SIZE_RATIO_4_3},
    {  352,  288, SIZE_RATIO_11_9},
    {  320,  240, SIZE_RATIO_4_3},
    {  256,  144, SIZE_RATIO_16_9}, /* for CAMERA2_API_SUPPORT */
    {  176,  144, SIZE_RATIO_11_9}
};

static int S5K3M3_HIDDEN_PREVIEW_LIST[][SIZE_OF_RESOLUTION] =
{
#if !(defined(CAMERA_LCD_SIZE) && (CAMERA_LCD_SIZE >= LCD_SIZE_1920_1080))
    { 1920, 1080, SIZE_RATIO_16_9},
    { 1440, 1080, SIZE_RATIO_4_3},
    { 1088, 1088, SIZE_RATIO_1_1},
#endif
    { 3840, 2160, SIZE_RATIO_16_9},
    { 3264, 1836, SIZE_RATIO_16_9},
    { 2560, 1440, SIZE_RATIO_16_9},
    { 2224, 1080, SIZE_RATIO_18P5_9},
    { 1600, 1200, SIZE_RATIO_4_3},
    { 1280,  960, SIZE_RATIO_4_3},
    { 1056,  864, SIZE_RATIO_11_9},
    {  960,  960, SIZE_RATIO_1_1},  /* for Clip Movie */
    {  960,  540, SIZE_RATIO_16_9},  /* for GearVR*/
    {  640,  360, SIZE_RATIO_16_9},  /* for SWIS & GearVR*/
    {  528,  432, SIZE_RATIO_11_9},
    {  800,  600, SIZE_RATIO_4_3},  /* for GearVR */
    {  800,  480, SIZE_RATIO_5_3},
    {  672,  448, SIZE_RATIO_3_2},
    {  480,  320, SIZE_RATIO_3_2},
    {  480,  270, SIZE_RATIO_16_9},
};

static int S5K3M3_PICTURE_LIST[][SIZE_OF_RESOLUTION] =
{
    { 4032, 3024, SIZE_RATIO_4_3},
    { 4032, 2268, SIZE_RATIO_16_9},
    { 3024, 3024, SIZE_RATIO_1_1},
    { 3984, 2988, SIZE_RATIO_4_3},
    { 3264, 2448, SIZE_RATIO_4_3},
    { 3264, 1836, SIZE_RATIO_16_9},
    { 2976, 2976, SIZE_RATIO_1_1},
    { 2880, 2160, SIZE_RATIO_4_3},
    { 2560, 1440, SIZE_RATIO_16_9},
    { 2160, 2160, SIZE_RATIO_1_1},
    { 2048, 1152, SIZE_RATIO_16_9},
    { 1920, 1080, SIZE_RATIO_16_9},
    { 1280,  720, SIZE_RATIO_16_9},
    {  960,  720, SIZE_RATIO_4_3},
    {  640,  480, SIZE_RATIO_4_3},
};

static int S5K3M3_HIDDEN_PICTURE_LIST[][SIZE_OF_RESOLUTION] =
{
    { 4128, 3096, SIZE_RATIO_4_3},
    { 4128, 2322, SIZE_RATIO_16_9},
    { 4096, 3072, SIZE_RATIO_4_3},
    { 4096, 2304, SIZE_RATIO_16_9},
    { 4032, 1960, SIZE_RATIO_18P5_9},
    { 3840, 2160, SIZE_RATIO_16_9},
    { 3200, 2400, SIZE_RATIO_4_3},
    { 3072, 1728, SIZE_RATIO_16_9},
    { 2988, 2988, SIZE_RATIO_1_1},
    { 2656, 1494, SIZE_RATIO_16_9}, /* use S-note */
    { 2592, 1944, SIZE_RATIO_4_3},
    { 2592, 1936, SIZE_RATIO_4_3},  /* not exactly matched ratio */
    { 2560, 1920, SIZE_RATIO_4_3},
    { 2448, 2448, SIZE_RATIO_1_1},
    { 2048, 1536, SIZE_RATIO_4_3},
    { 1440, 1080, SIZE_RATIO_4_3},	/* binning capture */
    { 1080, 1080, SIZE_RATIO_1_1},	/* binning capture */
    { 1616, 1080, SIZE_RATIO_3_2},	/* binning capture */
    { 1232, 1008, SIZE_RATIO_11_9},	/* binning capture */
    { 1056,  704, SIZE_RATIO_3_2},	/* binning capture */
    {  720,  720, SIZE_RATIO_1_1}, /* dummy size for binning mode */
    {  352,  288, SIZE_RATIO_11_9}, /* dummy size for binning mode */
};

static int S5K3M3_THUMBNAIL_LIST[][SIZE_OF_RESOLUTION] =
{
    {  512,  384, SIZE_RATIO_4_3},
    {  512,  288, SIZE_RATIO_16_9},
    {  384,  384, SIZE_RATIO_1_1},
/* TODO : will be supported after enable S/W scaler correctly */
//  {  320,  240, SIZE_RATIO_4_3},
    {    0,    0, SIZE_RATIO_1_1}
};

static int S5K3M3_VIDEO_LIST[][SIZE_OF_RESOLUTION] =
{
    { 1920, 1080, SIZE_RATIO_16_9},
    { 1440, 1440, SIZE_RATIO_1_1},
    { 1440, 1080, SIZE_RATIO_4_3},
    { 1088, 1088, SIZE_RATIO_1_1},
    { 1280,  720, SIZE_RATIO_16_9},
    {  960,  720, SIZE_RATIO_4_3},
    {  800,  450, SIZE_RATIO_16_9},
    {  720,  480, SIZE_RATIO_3_2},
    {  640,  480, SIZE_RATIO_4_3},
    {  480,  320, SIZE_RATIO_3_2},
    {  352,  288, SIZE_RATIO_11_9},
    {  320,  240, SIZE_RATIO_4_3},
    {  256,  144, SIZE_RATIO_16_9}, /* for CAMERA2_API_SUPPORT */
    {  176,  144, SIZE_RATIO_11_9},
};

static int S5K3M3_HIDDEN_VIDEO_LIST[][SIZE_OF_RESOLUTION] =
{
#ifdef USE_UHD_RECORDING
    { 3840, 2160, SIZE_RATIO_16_9},
#endif
#ifdef USE_WQHD_RECORDING
    { 2560, 1440, SIZE_RATIO_16_9},
#endif
    {  960,  960, SIZE_RATIO_1_1},  /* for Clip Movie */
    {  864,  480, SIZE_RATIO_16_9}, /* for PLB mode */
    {  432,  240, SIZE_RATIO_16_9}, /* for PLB mode */
};

/* For HAL3 */
static int S5K3M3_YUV_LIST[][SIZE_OF_RESOLUTION] =
{
    { 4032, 3024, SIZE_RATIO_4_3},
    { 4032, 2268, SIZE_RATIO_16_9},
    { 3024, 3024, SIZE_RATIO_1_1},
    { 3984, 2988, SIZE_RATIO_4_3},
    { 3264, 2448, SIZE_RATIO_4_3},
    { 3264, 1836, SIZE_RATIO_16_9},
    { 2976, 2976, SIZE_RATIO_1_1},
    { 2880, 2160, SIZE_RATIO_4_3},
    { 2560, 1440, SIZE_RATIO_16_9},
    { 2160, 2160, SIZE_RATIO_1_1},
    { 2048, 1152, SIZE_RATIO_16_9},
    { 1920, 1080, SIZE_RATIO_16_9},
    { 1440, 1080, SIZE_RATIO_4_3},
    { 1088, 1088, SIZE_RATIO_1_1},
    { 1280,  720, SIZE_RATIO_16_9},
    { 1056,  704, SIZE_RATIO_3_2},
    { 1024,  768, SIZE_RATIO_4_3},
    {  960,  720, SIZE_RATIO_4_3},
    {  800,  450, SIZE_RATIO_16_9},
    {  720,  720, SIZE_RATIO_1_1},
    {  720,  480, SIZE_RATIO_3_2},
    {  640,  480, SIZE_RATIO_4_3},
    {  352,  288, SIZE_RATIO_11_9},
    {  320,  240, SIZE_RATIO_4_3},
    {  256,  144, SIZE_RATIO_16_9}, /* DngCreatorTest */
    {  176,  144, SIZE_RATIO_11_9}, /* RecordingTest */
};

/* availble Jpeg size (only for  HAL_PIXEL_FORMAT_BLOB) */
static int S5K3M3_JPEG_LIST[][SIZE_OF_RESOLUTION] =
{
    { 4032, 3024, SIZE_RATIO_4_3},
    { 4032, 2268, SIZE_RATIO_16_9},
    { 3024, 3024, SIZE_RATIO_1_1},
    { 3984, 2988, SIZE_RATIO_4_3},
    { 3264, 2448, SIZE_RATIO_4_3},
    { 3264, 1836, SIZE_RATIO_16_9},
    { 2976, 2976, SIZE_RATIO_1_1},
    { 2880, 2160, SIZE_RATIO_4_3},
    { 2560, 1440, SIZE_RATIO_16_9},
    { 2160, 2160, SIZE_RATIO_1_1},
    { 2048, 1152, SIZE_RATIO_16_9},
    { 1920, 1080, SIZE_RATIO_16_9},
    { 1440, 1080, SIZE_RATIO_4_3},
    { 1088, 1088, SIZE_RATIO_1_1},
    { 1280,  720, SIZE_RATIO_16_9},
    { 1056,  704, SIZE_RATIO_3_2},
    { 1024,  768, SIZE_RATIO_4_3},
    {  960,  720, SIZE_RATIO_4_3},
    {  800,  450, SIZE_RATIO_16_9},
    {  720,  720, SIZE_RATIO_1_1},
    {  720,  480, SIZE_RATIO_3_2},
    {  640,  480, SIZE_RATIO_4_3},
    {  352,  288, SIZE_RATIO_11_9},
    {  320,  240, SIZE_RATIO_4_3},
};


/* For HAL3 */
static int S5K3M3_HIGH_SPEED_VIDEO_LIST[][SIZE_OF_RESOLUTION] =
{
    { 1280,  720, SIZE_RATIO_16_9},
};

static int S5K3M3_FPS_RANGE_LIST[][2] =
{
    //{   5000,   5000},
    //{   7000,   7000},
    {  15000,  15000},
    {  24000,  24000},
    //{   4000,  30000},
    {  10000,  30000},
    {  15000,  30000},
    {  30000,  30000},
};

static int S5K3M3_HIDDEN_FPS_RANGE_LIST[][2] =
{
    {   5000,   5000},
    {  10000,  24000},
    {  30000,  60000},
    {  60000,  60000},
    {  60000, 120000},
    { 120000, 120000},
};

/* For HAL3 */
static int S5K3M3_HIGH_SPEED_VIDEO_FPS_RANGE_LIST[][2] =
{
    {  30000, 120000},
    { 120000, 120000},
};

static camera_metadata_rational UNIT_MATRIX_3M3_3X3[] =
{
    {128, 128}, {0, 128}, {0, 128},
    {0, 128}, {128, 128}, {0, 128},
    {0, 128}, {0, 128}, {128, 128}
};

static camera_metadata_rational COLOR_MATRIX1_3M3_3X3[] =
{
    {593, 1024},  {78, 1024},  {-118, 1024},
    {-491, 1024}, {1412, 1024},{72, 1024},
    {-137, 1024}, {417, 1024}, {428, 1024}
};

static camera_metadata_rational COLOR_MATRIX2_3M3_3X3[] =
{
    {1032, 1024}, {-174, 1024}, {-276, 1024},
    {-442, 1024}, {1495, 1024}, {39, 1024},
    {-76, 1024},  {333, 1024},  {614, 1024}
};

static camera_metadata_rational FORWARD_MATRIX1_3M3_3X3[] =
{
    {893, 1024}, {-200, 1024}, {294, 1024},
    {317, 1024}, {697, 1024},  {10, 1024},
    {-16, 1024}, {-557, 1024}, {1418, 1024}
};

static camera_metadata_rational FORWARD_MATRIX2_3M3_3X3[] =
{
    {750, 1024}, {-150, 1024}, {387, 1024},
    {186, 1024}, {748, 1024},  {90, 1024},
    {-55, 1024}, {-987, 1024}, {1887, 1024}
};

#endif
