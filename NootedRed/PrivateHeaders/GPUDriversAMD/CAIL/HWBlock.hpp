// Copyright © 2024-2025 ChefKiss. Licensed under the Thou Shalt Not Profit License version 1.5.
// See LICENSE for details.

#pragma once
#include <IOKit/IOTypes.h>

//-------- AMD HW Block Type --------//

// XX: No VPE, LSDMA, XGMI?
// [insert relevant megamind picture here]
enum CAILHWBlock {
    kCAILHWBlockUnknown = 0,
    // XX: Where is 1, 2, 3? Maybe those are VPE, LSDMA, XGMI? get_hw_block_type doesn't seem to reference them
    kCAILHWBlockMP1 = 4,
    kCAILHWBlockMP2,
    kCAILHWBlockTHM,
    kCAILHWBlockSMUIO,
    kCAILHWBlockFUSE,
    kCAILHWBlockCLKA,
    kCAILHWBlockPWR,
    kCAILHWBlockGC,
    kCAILHWBlockUVD,
    kCAILHWBlockVCN = kCAILHWBlockUVD,
    kCAILHWBlockAUDIO_AZ,
    kCAILHWBlockACP,
    kCAILHWBlockDCI,
    kCAILHWBlockDMU,
    kCAILHWBlockDCO,
    kCAILHWBlockDIO,
    kCAILHWBlockXDMA,
    kCAILHWBlockDCEAZ,
    kCAILHWBlockDAZ,
    kCAILHWBlockSDPMUX,
    kCAILHWBlockNTB,
    kCAILHWBlockIOHC,
    kCAILHWBlockL2IMU,
    kCAILHWBlockVCE,
    kCAILHWBlockMMHUB,
    kCAILHWBlockATHUB,
    kCAILHWBlockDBGU_NBIO,
    kCAILHWBlockDFX,
    kCAILHWBlockDBGU0,
    kCAILHWBlockDBGU1,
    kCAILHWBlockOSSSYS,
    kCAILHWBlockHDP,
    kCAILHWBlockSDMA0,
    kCAILHWBlockSDMA1,
    kCAILHWBlockISP,
    kCAILHWBlockDBGU_IO,
    kCAILHWBlockDF,
    kCAILHWBlockCLKB,
    kCAILHWBlockFCH,
    kCAILHWBlockDFX_DAP,
    kCAILHWBlockL1IMU_PCIE,
    kCAILHWBlockL1IMU_NBIF,
    kCAILHWBlockL1IMU_IOAGR,
    kCAILHWBlockL1IMU3,
    kCAILHWBlockL1IMU4,
    kCAILHWBlockL1IMU5,
    kCAILHWBlockL1IMU6,
    kCAILHWBlockL1IMU7,
    kCAILHWBlockL1IMU8,
    kCAILHWBlockL1IMU9,
    kCAILHWBlockL1IMU10,
    kCAILHWBlockL1IMU11,
    kCAILHWBlockL1IMU12,
    kCAILHWBlockL1IMU13,
    kCAILHWBlockL1IMU14,
    kCAILHWBlockL1IMU15,
    kCAILHWBlockWAFLC,
    kCAILHWBlockFCH_USB_PD,
    kCAILHWBlockPCIE,
    kCAILHWBlockPCS,
    kCAILHWBlockDDCL,
    kCAILHWBlockSST,
    kCAILHWBlockIOAGR,
    kCAILHWBlockNBIF,
    kCAILHWBlockIOAPIC,
    kCAILHWBlockSYSTEMHUB,
    kCAILHWBlockNTBCCP,
    kCAILHWBlockUMC,
    kCAILHWBlockSATA,
    kCAILHWBlockUSB,
    kCAILHWBlockCCXSEC,
    kCAILHWBlockXGBE,
    kCAILHWBlockMP0,
    kCAILHWBlockSDMA2,
    kCAILHWBlockSDMA3,
};
