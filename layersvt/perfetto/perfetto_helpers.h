#ifndef LAYERSVT_PERFETTO_HELPERS_H
#define LAYERSVT_PERFETTO_HELPERS_H

#include "perfetto.h"

// Define categories
PERFETTO_DEFINE_CATEGORIES(
    perfetto::Category("CPUTiming").SetDescription("Vulkan CPU Timing Layer")
);

void InitializePerfetto();

#endif // LAYERSVT_PERFETTO_HELPERS_H
