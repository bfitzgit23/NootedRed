// Copyright © 2022-2025 ChefKiss. Licensed under the Thou Shalt Not Profit License version 1.5.
// See LICENSE for details.

#pragma once
#include <Headers/kern_patcher.hpp>

namespace PatcherPlus {
    struct PatternSolveRequest : KernelPatcher::SolveRequest {
        const UInt8 *pattern {nullptr}, *mask {nullptr};
        size_t patternSize {0};

        template<typename T>
        PatternSolveRequest(const char *s, T &addr) : KernelPatcher::SolveRequest {s, addr} {}

        template<typename T, typename P, size_t N>
        PatternSolveRequest(const char *s, T &addr, const P (&pattern)[N])
            : KernelPatcher::SolveRequest {s, addr}, pattern {pattern}, patternSize {N} {}

        template<typename T, typename P, size_t N>
        PatternSolveRequest(const char *s, T &addr, const P (&pattern)[N], const UInt8 (&mask)[N])
            : KernelPatcher::SolveRequest {s, addr}, pattern {pattern}, mask {mask}, patternSize {N} {}

        bool solve(KernelPatcher &patcher, size_t id, mach_vm_address_t address, size_t maxSize);

        static bool solveAll(KernelPatcher &patcher, size_t id, PatternSolveRequest *requests, size_t count,
            mach_vm_address_t address, size_t maxSize);

        template<size_t N>
        static bool solveAll(KernelPatcher &patcher, size_t id, PatternSolveRequest (&requests)[N],
            mach_vm_address_t address, size_t maxSize) {
            return solveAll(patcher, id, requests, N, address, maxSize);
        }
    };

    struct PatternRouteRequest : KernelPatcher::RouteRequest {
        const UInt8 *pattern {nullptr}, *mask {nullptr};
        size_t patternSize {0};

        template<typename T>
        PatternRouteRequest(const char *s, T t, mach_vm_address_t &o) : KernelPatcher::RouteRequest {s, t, o} {}

        template<typename T, typename O>
        PatternRouteRequest(const char *s, T t, O &o) : KernelPatcher::RouteRequest {s, t, o} {}

        template<typename T>
        PatternRouteRequest(const char *s, T t) : KernelPatcher::RouteRequest {s, t} {}

        template<typename T, typename P, size_t N>
        PatternRouteRequest(const char *s, T t, mach_vm_address_t &o, const P (&pattern)[N])
            : KernelPatcher::RouteRequest {s, t, o}, pattern {pattern}, patternSize {N} {}

        template<typename T, typename O, typename P, size_t N>
        PatternRouteRequest(const char *s, T t, O &o, const P (&pattern)[N])
            : KernelPatcher::RouteRequest {s, t, o}, pattern {pattern}, patternSize {N} {}

        template<typename T, typename P, size_t N>
        PatternRouteRequest(const char *s, T t, const P (&pattern)[N])
            : KernelPatcher::RouteRequest {s, t}, pattern {pattern}, patternSize {N} {}

        template<typename T, typename P, size_t N>
        PatternRouteRequest(const char *s, T t, mach_vm_address_t &o, const P (&pattern)[N], const UInt8 (&mask)[N])
            : KernelPatcher::RouteRequest {s, t, o}, pattern {pattern}, mask {mask}, patternSize {N} {}

        template<typename T, typename O, typename P, size_t N>
        PatternRouteRequest(const char *s, T t, O &o, const P (&pattern)[N], const UInt8 (&mask)[N])
            : KernelPatcher::RouteRequest {s, t, o}, pattern {pattern}, mask {mask}, patternSize {N} {}

        template<typename T, typename P, size_t N>
        PatternRouteRequest(const char *s, T t, const P (&pattern)[N], const UInt8 (&mask)[N])
            : KernelPatcher::RouteRequest {s, t}, pattern {pattern}, mask {mask}, patternSize {N} {}

        bool route(KernelPatcher &patcher, size_t id, mach_vm_address_t address, size_t maxSize);

        static bool routeAll(KernelPatcher &patcher, size_t id, PatternRouteRequest *requests, size_t count,
            mach_vm_address_t address, size_t maxSize);

        template<size_t N>
        static bool routeAll(KernelPatcher &patcher, size_t id, PatternRouteRequest (&requests)[N],
            mach_vm_address_t address, size_t maxSize) {
            return routeAll(patcher, id, requests, N, address, maxSize);
        }
    };

    struct MaskedLookupPatch : KernelPatcher::LookupPatch {
        const UInt8 *findMask {nullptr}, *replaceMask {nullptr};
        const size_t skip {0};

        MaskedLookupPatch(KernelPatcher::KextInfo *kext, const UInt8 *find, const UInt8 *replace, size_t size,
            size_t count, size_t skip = 0)
            : KernelPatcher::LookupPatch {kext, find, replace, size, count}, skip {skip} {}

        MaskedLookupPatch(KernelPatcher::KextInfo *kext, const UInt8 *find, const UInt8 *findMask, const UInt8 *replace,
            size_t size, size_t count, size_t skip = 0)
            : KernelPatcher::LookupPatch {kext, find, replace, size, count}, findMask {findMask}, skip {skip} {}

        MaskedLookupPatch(KernelPatcher::KextInfo *kext, const UInt8 *find, const UInt8 *findMask, const UInt8 *replace,
            const UInt8 *replaceMask, size_t size, size_t count, size_t skip = 0)
            : KernelPatcher::LookupPatch {kext, find, replace, size, count}, findMask {findMask},
              replaceMask {replaceMask}, skip {skip} {}

        template<size_t N>
        MaskedLookupPatch(KernelPatcher::KextInfo *kext, const UInt8 (&find)[N], const UInt8 (&replace)[N],
            size_t count, size_t skip = 0)
            : MaskedLookupPatch {kext, find, replace, N, count, skip} {}

        template<size_t N>
        MaskedLookupPatch(KernelPatcher::KextInfo *kext, const UInt8 (&find)[N], const UInt8 (&findMask)[N],
            const UInt8 (&replace)[N], size_t count, size_t skip = 0)
            : MaskedLookupPatch {kext, find, findMask, replace, N, count, skip} {}

        template<size_t N>
        MaskedLookupPatch(KernelPatcher::KextInfo *kext, const UInt8 (&find)[N], const UInt8 (&findMask)[N],
            const UInt8 (&replace)[N], const UInt8 (&replaceMask)[N], size_t count, size_t skip = 0)
            : MaskedLookupPatch {kext, find, findMask, replace, replaceMask, N, count, skip} {}

        bool apply(KernelPatcher &patcher, mach_vm_address_t address, size_t maxSize) const;

        static bool applyAll(KernelPatcher &patcher, const MaskedLookupPatch *patches, size_t count,
            mach_vm_address_t address, size_t maxSize, bool force = false);

        template<size_t N>
        static bool applyAll(KernelPatcher &patcher, const MaskedLookupPatch (&patches)[N], mach_vm_address_t address,
            size_t maxSize, bool force = false) {
            return applyAll(patcher, patches, N, address, maxSize, force);
        }
    };

    mach_vm_address_t jumpInstDestination(mach_vm_address_t address);

    struct JumpPatternRouteRequest : KernelPatcher::RouteRequest {
        const UInt8 *pattern {nullptr}, *mask {nullptr};
        size_t patternSize {0};
        size_t jumpInstOff {0};

        template<typename T>
        JumpPatternRouteRequest(const char *s, T t) : KernelPatcher::RouteRequest {s, t} {}

        template<typename T>
        JumpPatternRouteRequest(const char *s, T t, mach_vm_address_t &o) : KernelPatcher::RouteRequest {s, t, o} {}

        template<typename T, typename O>
        JumpPatternRouteRequest(const char *s, T t, O &o) : KernelPatcher::RouteRequest {s, t, o} {}

        template<typename T, typename P, size_t N>
        JumpPatternRouteRequest(const char *s, T t, mach_vm_address_t &o, const P (&pattern)[N],
            const size_t jumpInstOff)
            : KernelPatcher::RouteRequest {s, t, o}, pattern {pattern}, patternSize {N}, jumpInstOff {jumpInstOff} {}

        template<typename T, typename O, typename P, size_t N>
        JumpPatternRouteRequest(const char *s, T t, O &o, const P (&pattern)[N], const size_t jumpInstOff)
            : KernelPatcher::RouteRequest {s, t, o}, pattern {pattern}, patternSize {N}, jumpInstOff {jumpInstOff} {}

        template<typename T, typename P, size_t N>
        JumpPatternRouteRequest(const char *s, T t, const P (&pattern)[N], const size_t jumpInstOff)
            : KernelPatcher::RouteRequest {s, t}, pattern {pattern}, patternSize {N}, jumpInstOff {jumpInstOff} {}

        template<typename T, typename P, size_t N>
        JumpPatternRouteRequest(const char *s, T t, mach_vm_address_t &o, const P (&pattern)[N], const UInt8 (&mask)[N],
            const size_t jumpInstOff)
            : KernelPatcher::RouteRequest {s, t, o}, pattern {pattern}, mask {mask}, patternSize {N},
              jumpInstOff {jumpInstOff} {}

        template<typename T, typename O, typename P, size_t N>
        JumpPatternRouteRequest(const char *s, T t, O &o, const P (&pattern)[N], const UInt8 (&mask)[N],
            const size_t jumpInstOff)
            : KernelPatcher::RouteRequest {s, t, o}, pattern {pattern}, mask {mask}, patternSize {N},
              jumpInstOff {jumpInstOff} {}

        template<typename T, typename P, size_t N>
        JumpPatternRouteRequest(const char *s, T t, const P (&pattern)[N], const UInt8 (&mask)[N],
            const size_t jumpInstOff)
            : KernelPatcher::RouteRequest {s, t}, pattern {pattern}, mask {mask}, patternSize {N},
              jumpInstOff {jumpInstOff} {}

        bool route(KernelPatcher &patcher, size_t id, mach_vm_address_t address, size_t maxSize);

        static bool routeAll(KernelPatcher &patcher, size_t id, JumpPatternRouteRequest *requests, size_t count,
            mach_vm_address_t address, size_t maxSize);

        template<size_t N>
        static bool routeAll(KernelPatcher &patcher, size_t id, JumpPatternRouteRequest (&requests)[N],
            mach_vm_address_t address, size_t maxSize) {
            return routeAll(patcher, id, requests, N, address, maxSize);
        }
    };
}    // namespace PatcherPlus
