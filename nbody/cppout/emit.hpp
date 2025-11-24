#include "cppruntime.hpp"
#include "gc/src/runtime/memory/gc.h"
#include "gc/src/runtime/memory/threadinfo.h"
[[maybe_unused]] constexpr auto subtypes = []() constexpr { __CoreCpp::SubtypeTable<72> s{};
     s.set<7, 3, 5, 8>();
     s.set<15, 10, 13, 16>();
     s.set<26, 17, 24, 27>();
     s.set<32, 28, 30, 33>();
     s.set<37, 34, 35, 38>();
     s.set<43, 39, 41, 44>();
     s.set<48, 45, 46, 49>();
     s.set<60, 58, 59>();
     s.set<62, 58, 61>();
     s.set<64, 58, 63>();
     s.set<66, 58, 65>();
     s.set<68, 58, 67>();
     s.set<70, 58, 69>();
     s.set<72, 58, 71>();
return s;}();
//
// Primitive Types
//
__CoreGC::TypeInfoBase Bool𝐓𝐲𝐩𝐞 = {
    .type_id = 50,
    .type_size = 8, 
    .slot_size = 1,
    .tag = __CoreGC::Tag::Value,
    .ptr_mask = "0",
    .typekey = "__CoreCpp::Bool",
    .vtable = nullptr
};
__CoreGC::TypeInfoBase CCharBuffer𝐓𝐲𝐩𝐞 = {
    .type_id = 4,
    .type_size = 16, 
    .slot_size = 2,
    .tag = __CoreGC::Tag::Value,
    .ptr_mask = "00",
    .typekey = "__CoreCpp::CCharBuffer",
    .vtable = nullptr
};
__CoreGC::TypeInfoBase Float𝐓𝐲𝐩𝐞 = {
    .type_id = 11,
    .type_size = 8, 
    .slot_size = 1,
    .tag = __CoreGC::Tag::Value,
    .ptr_mask = "0",
    .typekey = "__CoreCpp::Float",
    .vtable = nullptr
};
__CoreGC::TypeInfoBase Nat𝐓𝐲𝐩𝐞 = {
    .type_id = 1,
    .type_size = 8, 
    .slot_size = 1,
    .tag = __CoreGC::Tag::Value,
    .ptr_mask = "0",
    .typekey = "__CoreCpp::Nat",
    .vtable = nullptr
};
__CoreGC::TypeInfoBase None𝐓𝐲𝐩𝐞 = {
    .type_id = 58,
    .type_size = 0, 
    .slot_size = 0,
    .tag = __CoreGC::Tag::Value,
    .ptr_mask = nullptr,
    .typekey = "__CoreCpp::None",
    .vtable = nullptr
};
//
// Ref and Tagged Type Forward Declarations (and collections)
//
namespace Core {
    typedef __CoreCpp::Boxed<1> OptionᐸCRopeOpsᘏNodeᐳ;
    typedef __CoreCpp::Boxed<1> OptionᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ;
    typedef __CoreCpp::Boxed<1> OptionᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ;
    typedef __CoreCpp::Boxed<1> OptionᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ;
    typedef __CoreCpp::Boxed<1> OptionᐸListOpsᘏNodeᐸFloatᐳᐳ;
    typedef __CoreCpp::Boxed<1> OptionᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ;
    typedef __CoreCpp::Boxed<1> OptionᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ;
    struct SomeᐸCRopeOpsᘏNodeᐳ;
    struct SomeᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ;
    struct SomeᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ;
    struct SomeᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ;
    struct SomeᐸListOpsᘏNodeᐸFloatᐳᐳ;
    struct SomeᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ;
    struct SomeᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ;
    namespace Algorithm {
    }
    namespace CCharBufferOps {
    }
    namespace CRopeOps {
        struct BBLeaf;
        struct Leaf;
        struct Node;
        typedef __CoreCpp::Boxed<2> Rope;
    }
    namespace ListOps {
        struct BBLeafᐸ丨FloatᐧFloatᐧFloat丨ᐳ;
        struct BBLeafᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ;
        struct BBLeafᐸ丨NatᐧNat丨ᐳ;
        struct BBLeafᐸFloatᐳ;
        struct BBLeafᐸListᐸ丨NatᐧNat丨ᐳᐳ;
        struct BBLeafᐸMainᘏBodyᐳ;
        struct Leafᐸ丨FloatᐧFloatᐧFloat丨ᐳ;
        struct Leafᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ;
        struct Leafᐸ丨NatᐧNat丨ᐳ;
        struct LeafᐸFloatᐳ;
        struct LeafᐸListᐸ丨NatᐧNat丨ᐳᐳ;
        struct LeafᐸMainᘏBodyᐳ;
        struct Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ;
        struct Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ;
        struct Nodeᐸ丨NatᐧNat丨ᐳ;
        struct NodeᐸFloatᐳ;
        struct NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ;
        struct NodeᐸMainᘏBodyᐳ;
        typedef __CoreCpp::Boxed<3> Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ;
        typedef __CoreCpp::Boxed<1> Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ;
        typedef __CoreCpp::Boxed<2> Treeᐸ丨NatᐧNat丨ᐳ;
        typedef __CoreCpp::Boxed<1> TreeᐸFloatᐳ;
        typedef __CoreCpp::Boxed<1> TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ;
        typedef __CoreCpp::Boxed<1> TreeᐸMainᘏBodyᐳ;
    }
    namespace NumericOps {
    }
}
namespace Main {
    struct Body;
    struct NBodySystem;
    struct Position;
    struct Velocity;
}
namespace Core {
    typedef CRopeOps::Rope CRope;
    typedef CRope CString;
    typedef ListOps::Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ Listᐸ丨FloatᐧFloatᐧFloat丨ᐳ;
    typedef ListOps::Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ Listᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ;
    typedef ListOps::Treeᐸ丨NatᐧNat丨ᐳ Listᐸ丨NatᐧNat丨ᐳ;
    typedef ListOps::TreeᐸFloatᐳ ListᐸFloatᐳ;
    typedef ListOps::TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ ListᐸListᐸ丨NatᐧNat丨ᐳᐳ;
    typedef ListOps::TreeᐸMainᘏBodyᐳ ListᐸMainᘏBodyᐳ;
}
namespace Main {
}
namespace Core {
}
namespace Main {
}
namespace Core {
//
// Value Type Definitions
//
    typedef __CoreCpp::CRopeIterator CRopeIterator;
    __CoreGC::TypeInfoBase SomeᐸCRopeOpsᘏNodeᐳ𝐓𝐲𝐩𝐞 = {
        .type_id = 59,
        .type_size = 8, 
        .slot_size = 1,
        .tag = __CoreGC::Tag::Value,
        .ptr_mask = "1",
        .typekey = "Some<CRopeOps::Node>",
        .vtable = nullptr
    };
    struct SomeᐸCRopeOpsᘏNodeᐳ {
        CRopeOps::Node* value;
    };
    __CoreGC::TypeInfoBase SomeᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ𝐓𝐲𝐩𝐞 = {
        .type_id = 61,
        .type_size = 8, 
        .slot_size = 1,
        .tag = __CoreGC::Tag::Value,
        .ptr_mask = "1",
        .typekey = "Some<ListOps::Node<(|Float, Float, Float|)>>",
        .vtable = nullptr
    };
    struct SomeᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ {
        ListOps::Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ* value;
    };
    __CoreGC::TypeInfoBase SomeᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ𝐓𝐲𝐩𝐞 = {
        .type_id = 63,
        .type_size = 8, 
        .slot_size = 1,
        .tag = __CoreGC::Tag::Value,
        .ptr_mask = "1",
        .typekey = "Some<ListOps::Node<(|Main::Body, Float, Float, Float|)>>",
        .vtable = nullptr
    };
    struct SomeᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ {
        ListOps::Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ* value;
    };
    __CoreGC::TypeInfoBase SomeᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞 = {
        .type_id = 65,
        .type_size = 8, 
        .slot_size = 1,
        .tag = __CoreGC::Tag::Value,
        .ptr_mask = "1",
        .typekey = "Some<ListOps::Node<(|Nat, Nat|)>>",
        .vtable = nullptr
    };
    struct SomeᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ {
        ListOps::Nodeᐸ丨NatᐧNat丨ᐳ* value;
    };
    __CoreGC::TypeInfoBase SomeᐸListOpsᘏNodeᐸFloatᐳᐳ𝐓𝐲𝐩𝐞 = {
        .type_id = 67,
        .type_size = 8, 
        .slot_size = 1,
        .tag = __CoreGC::Tag::Value,
        .ptr_mask = "1",
        .typekey = "Some<ListOps::Node<Float>>",
        .vtable = nullptr
    };
    struct SomeᐸListOpsᘏNodeᐸFloatᐳᐳ {
        ListOps::NodeᐸFloatᐳ* value;
    };
    __CoreGC::TypeInfoBase SomeᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ𝐓𝐲𝐩𝐞 = {
        .type_id = 69,
        .type_size = 8, 
        .slot_size = 1,
        .tag = __CoreGC::Tag::Value,
        .ptr_mask = "1",
        .typekey = "Some<ListOps::Node<List<(|Nat, Nat|)>>>",
        .vtable = nullptr
    };
    struct SomeᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ {
        ListOps::NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ* value;
    };
    __CoreGC::TypeInfoBase SomeᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ𝐓𝐲𝐩𝐞 = {
        .type_id = 71,
        .type_size = 8, 
        .slot_size = 1,
        .tag = __CoreGC::Tag::Value,
        .ptr_mask = "1",
        .typekey = "Some<ListOps::Node<Main::Body>>",
        .vtable = nullptr
    };
    struct SomeᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ {
        ListOps::NodeᐸMainᘏBodyᐳ* value;
    };
//
// Ref and Tagged Type Definitions
//
    __CoreGC::TypeInfoBase OptionᐸCRopeOpsᘏNodeᐳ𝐓𝐲𝐩𝐞 = {
        .type_id = 60,
        .type_size = 16, 
        .slot_size = 2,
        .tag = __CoreGC::Tag::Tagged,
        .ptr_mask = "20",
        .typekey = "Option<CRopeOps::Node>",
        .vtable = nullptr
    };
    __CoreGC::TypeInfoBase OptionᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ𝐓𝐲𝐩𝐞 = {
        .type_id = 62,
        .type_size = 16, 
        .slot_size = 2,
        .tag = __CoreGC::Tag::Tagged,
        .ptr_mask = "20",
        .typekey = "Option<ListOps::Node<(|Float, Float, Float|)>>",
        .vtable = nullptr
    };
    __CoreGC::TypeInfoBase OptionᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ𝐓𝐲𝐩𝐞 = {
        .type_id = 64,
        .type_size = 16, 
        .slot_size = 2,
        .tag = __CoreGC::Tag::Tagged,
        .ptr_mask = "20",
        .typekey = "Option<ListOps::Node<(|Main::Body, Float, Float, Float|)>>",
        .vtable = nullptr
    };
    __CoreGC::TypeInfoBase OptionᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞 = {
        .type_id = 66,
        .type_size = 16, 
        .slot_size = 2,
        .tag = __CoreGC::Tag::Tagged,
        .ptr_mask = "20",
        .typekey = "Option<ListOps::Node<(|Nat, Nat|)>>",
        .vtable = nullptr
    };
    __CoreGC::TypeInfoBase OptionᐸListOpsᘏNodeᐸFloatᐳᐳ𝐓𝐲𝐩𝐞 = {
        .type_id = 68,
        .type_size = 16, 
        .slot_size = 2,
        .tag = __CoreGC::Tag::Tagged,
        .ptr_mask = "20",
        .typekey = "Option<ListOps::Node<Float>>",
        .vtable = nullptr
    };
    __CoreGC::TypeInfoBase OptionᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ𝐓𝐲𝐩𝐞 = {
        .type_id = 70,
        .type_size = 16, 
        .slot_size = 2,
        .tag = __CoreGC::Tag::Tagged,
        .ptr_mask = "20",
        .typekey = "Option<ListOps::Node<List<(|Nat, Nat|)>>>",
        .vtable = nullptr
    };
    __CoreGC::TypeInfoBase OptionᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ𝐓𝐲𝐩𝐞 = {
        .type_id = 72,
        .type_size = 16, 
        .slot_size = 2,
        .tag = __CoreGC::Tag::Tagged,
        .ptr_mask = "20",
        .typekey = "Option<ListOps::Node<Main::Body>>",
        .vtable = nullptr
    };
    __CoreGC::TypeInfoBase CRope𝐓𝐲𝐩𝐞 = {
        .type_id = 18,
        .type_size = 24, 
        .slot_size = 3,
        .tag = __CoreGC::Tag::Tagged,
        .ptr_mask = "200",
        .typekey = "CRope",
        .vtable = nullptr
    };
    __CoreGC::TypeInfoBase Listᐸ丨FloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞 = {
        .type_id = 52,
        .type_size = 32, 
        .slot_size = 4,
        .tag = __CoreGC::Tag::Tagged,
        .ptr_mask = "2000",
        .typekey = "List<(|Float, Float, Float|)>",
        .vtable = nullptr
    };
    __CoreGC::TypeInfoBase Listᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞 = {
        .type_id = 53,
        .type_size = 16, 
        .slot_size = 2,
        .tag = __CoreGC::Tag::Tagged,
        .ptr_mask = "20",
        .typekey = "List<(|Main::Body, Float, Float, Float|)>",
        .vtable = nullptr
    };
    __CoreGC::TypeInfoBase Listᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞 = {
        .type_id = 40,
        .type_size = 24, 
        .slot_size = 3,
        .tag = __CoreGC::Tag::Tagged,
        .ptr_mask = "200",
        .typekey = "List<(|Nat, Nat|)>",
        .vtable = nullptr
    };
    __CoreGC::TypeInfoBase ListᐸFloatᐳ𝐓𝐲𝐩𝐞 = {
        .type_id = 54,
        .type_size = 16, 
        .slot_size = 2,
        .tag = __CoreGC::Tag::Tagged,
        .ptr_mask = "20",
        .typekey = "List<Float>",
        .vtable = nullptr
    };
    __CoreGC::TypeInfoBase ListᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞 = {
        .type_id = 55,
        .type_size = 16, 
        .slot_size = 2,
        .tag = __CoreGC::Tag::Tagged,
        .ptr_mask = "20",
        .typekey = "List<List<(|Nat, Nat|)>>",
        .vtable = nullptr
    };
    __CoreGC::TypeInfoBase ListᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞 = {
        .type_id = 56,
        .type_size = 16, 
        .slot_size = 2,
        .tag = __CoreGC::Tag::Tagged,
        .ptr_mask = "20",
        .typekey = "List<Main::Body>",
        .vtable = nullptr
    };
//
// All Methods
//
    __CoreCpp::CCharBuffer CRopeIteratorᘏnext([[maybe_unused]] CRopeIterator &𝐭𝐡𝐢𝐬) noexcept;
    __CoreCpp::Bool CRopeIteratorᘏhasNext([[maybe_unused]] CRopeIterator &𝐭𝐡𝐢𝐬) noexcept;
    template <typename λfn_丨FloatᐧFloatᐧFloat丨_$Float_f>
    ListᐸFloatᐳ Listᐸ丨FloatᐧFloatᐧFloat丨ᐳᘏmapᐸFloatᐳ([[maybe_unused]] Listᐸ丨FloatᐧFloatᐧFloat丨ᐳ 𝐭𝐡𝐢𝐬, λfn_丨FloatᐧFloatᐧFloat丨_$Float_f&& f) noexcept;
    template <typename λfn_丨BodyᐧFloatᐧFloatᐧFloat丨_$MainᘏBody_f>
    ListᐸMainᘏBodyᐳ Listᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᘏmapᐸMainᘏBodyᐳ([[maybe_unused]] Listᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ 𝐭𝐡𝐢𝐬, λfn_丨BodyᐧFloatᐧFloatᐧFloat丨_$MainᘏBody_f&& f) noexcept;
    template <typename λfn_丨NatᐧNat丨_$Float_f>
    ListᐸFloatᐳ Listᐸ丨NatᐧNat丨ᐳᘏmapᐸFloatᐳ([[maybe_unused]] Listᐸ丨NatᐧNat丨ᐳ 𝐭𝐡𝐢𝐬, λfn_丨NatᐧNat丨_$Float_f&& f) noexcept;
    __CoreCpp::Float ListᐸFloatᐳᘏsum([[maybe_unused]] ListᐸFloatᐳ 𝐭𝐡𝐢𝐬) noexcept;
    template <typename λfn_Listᐸ丨NatᐧNat丨ᐳ_$Float_f>
    ListᐸFloatᐳ ListᐸListᐸ丨NatᐧNat丨ᐳᐳᘏmapᐸFloatᐳ([[maybe_unused]] ListᐸListᐸ丨NatᐧNat丨ᐳᐳ 𝐭𝐡𝐢𝐬, λfn_Listᐸ丨NatᐧNat丨ᐳ_$Float_f&& f) noexcept;
    __CoreCpp::Nat ListᐸMainᘏBodyᐳᘏsize([[maybe_unused]] ListᐸMainᘏBodyᐳ 𝐭𝐡𝐢𝐬) noexcept;
    Main::Body* ListᐸMainᘏBodyᐳᘏget([[maybe_unused]] ListᐸMainᘏBodyᐳ 𝐭𝐡𝐢𝐬, __CoreCpp::Nat i) noexcept;
    template <typename λfn_Body_$Float_f>
    ListᐸFloatᐳ ListᐸMainᘏBodyᐳᘏmapᐸFloatᐳ([[maybe_unused]] ListᐸMainᘏBodyᐳ 𝐭𝐡𝐢𝐬, λfn_Body_$Float_f&& f) noexcept;
    template <typename λfn_Body_$丨FloatᐧFloatᐧFloat丨_f>
    Listᐸ丨FloatᐧFloatᐧFloat丨ᐳ ListᐸMainᘏBodyᐳᘏmapᐸ丨FloatᐧFloatᐧFloat丨ᐳ([[maybe_unused]] ListᐸMainᘏBodyᐳ 𝐭𝐡𝐢𝐬, λfn_Body_$丨FloatᐧFloatᐧFloat丨_f&& f) noexcept;
    template <typename λfn_Body_$丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨_f>
    Listᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ ListᐸMainᘏBodyᐳᘏmapᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ([[maybe_unused]] ListᐸMainᘏBodyᐳ 𝐭𝐡𝐢𝐬, λfn_Body_$丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨_f&& f) noexcept;
    __CoreCpp::Nat CCharBufferᘏsize([[maybe_unused]] __CoreCpp::CCharBuffer 𝐭𝐡𝐢𝐬) noexcept;
    namespace Algorithm {
//
// Value Type Definitions
//
//
// Ref and Tagged Type Definitions
//
//
// All Methods
//
    }
    namespace CCharBufferOps {
//
// Value Type Definitions
//
//
// Ref and Tagged Type Definitions
//
//
// All Methods
//
    }
    namespace CRopeOps {
//
// Value Type Definitions
//
        __CoreGC::TypeInfoBase Color𝐓𝐲𝐩𝐞 = {
            .type_id = 2,
            .type_size = 8, 
            .slot_size = 1,
            .tag = __CoreGC::Tag::Value,
            .ptr_mask = "0",
            .typekey = "CRopeOps::Color",
            .vtable = nullptr
        };
        enum class Color : uint64_t {
            Red,
            Black,
            BB,
            NB
        };
        __CoreGC::TypeInfoBase BBLeaf𝐓𝐲𝐩𝐞 = {
            .type_id = 3,
            .type_size = 0, 
            .slot_size = 0,
            .tag = __CoreGC::Tag::Value,
            .ptr_mask = nullptr,
            .typekey = "CRopeOps::BBLeaf",
            .vtable = nullptr
        };
        struct BBLeaf{ 
        };
        static_assert(sizeof(BBLeaf) == 1);
        enum Leaf_entries : uintptr_t {
            Leaf_buf
        };
        const __CoreGC::FieldOffsetInfo Leaf_vtable[] = {
            { 4, Leaf_entries::Leaf_buf, 0 }
        };
        __CoreGC::TypeInfoBase Leaf𝐓𝐲𝐩𝐞 = {
            .type_id = 5,
            .type_size = 16, 
            .slot_size = 2,
            .tag = __CoreGC::Tag::Value,
            .ptr_mask = "00",
            .typekey = "CRopeOps::Leaf",
            .vtable = nullptr
        };
        struct Leaf{ 
            __CoreCpp::CCharBuffer buf;
        };
        static_assert(sizeof(Leaf) == 16);
//
// Ref and Tagged Type Definitions
//
        enum Node_entries : uintptr_t {
            Node_c,
            Node_w,
            Node_l,
            Node_r
        };
        const __CoreGC::FieldOffsetInfo Node_vtable[] = {
            { 2, Node_entries::Node_c, 0 },
            { 1, Node_entries::Node_w, 8 },
            { 7, Node_entries::Node_l, 16 },
            { 7, Node_entries::Node_r, 24 }
        };
        __CoreGC::TypeInfoBase Node𝐓𝐲𝐩𝐞 = {
            .type_id = 8,
            .type_size = 64, 
            .slot_size = 8,
            .tag = __CoreGC::Tag::Ref,
            .ptr_mask = "00200200",
            .typekey = "CRopeOps::Node",
            .vtable = nullptr
        };
        struct Node{ 
            Color c;
            __CoreCpp::Nat w;
            Rope l;
            Rope r;
        };
        static_assert(sizeof(Node) == 64);
        __CoreGC::TypeInfoBase Rope𝐓𝐲𝐩𝐞 = {
            .type_id = 7,
            .type_size = 24, 
            .slot_size = 3,
            .tag = __CoreGC::Tag::Tagged,
            .ptr_mask = "200",
            .typekey = "CRopeOps::Rope",
            .vtable = nullptr
        };
//
// All Methods
//
    }
    namespace ListOps {
//
// Value Type Definitions
//
        __CoreGC::TypeInfoBase Color𝐓𝐲𝐩𝐞 = {
            .type_id = 9,
            .type_size = 8, 
            .slot_size = 1,
            .tag = __CoreGC::Tag::Value,
            .ptr_mask = "0",
            .typekey = "ListOps::Color",
            .vtable = nullptr
        };
        enum class Color : uint64_t {
            Red,
            Black,
            BB,
            NB
        };
        __CoreGC::TypeInfoBase BBLeafᐸ丨FloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞 = {
            .type_id = 10,
            .type_size = 0, 
            .slot_size = 0,
            .tag = __CoreGC::Tag::Value,
            .ptr_mask = nullptr,
            .typekey = "ListOps::BBLeaf<(|Float, Float, Float|)>",
            .vtable = nullptr
        };
        struct BBLeafᐸ丨FloatᐧFloatᐧFloat丨ᐳ{ 
        };
        static_assert(sizeof(BBLeafᐸ丨FloatᐧFloatᐧFloat丨ᐳ) == 1);
        __CoreGC::TypeInfoBase BBLeafᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞 = {
            .type_id = 17,
            .type_size = 0, 
            .slot_size = 0,
            .tag = __CoreGC::Tag::Value,
            .ptr_mask = nullptr,
            .typekey = "ListOps::BBLeaf<(|Main::Body, Float, Float, Float|)>",
            .vtable = nullptr
        };
        struct BBLeafᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ{ 
        };
        static_assert(sizeof(BBLeafᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ) == 1);
        __CoreGC::TypeInfoBase BBLeafᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞 = {
            .type_id = 28,
            .type_size = 0, 
            .slot_size = 0,
            .tag = __CoreGC::Tag::Value,
            .ptr_mask = nullptr,
            .typekey = "ListOps::BBLeaf<(|Nat, Nat|)>",
            .vtable = nullptr
        };
        struct BBLeafᐸ丨NatᐧNat丨ᐳ{ 
        };
        static_assert(sizeof(BBLeafᐸ丨NatᐧNat丨ᐳ) == 1);
        __CoreGC::TypeInfoBase BBLeafᐸFloatᐳ𝐓𝐲𝐩𝐞 = {
            .type_id = 34,
            .type_size = 0, 
            .slot_size = 0,
            .tag = __CoreGC::Tag::Value,
            .ptr_mask = nullptr,
            .typekey = "ListOps::BBLeaf<Float>",
            .vtable = nullptr
        };
        struct BBLeafᐸFloatᐳ{ 
        };
        static_assert(sizeof(BBLeafᐸFloatᐳ) == 1);
        __CoreGC::TypeInfoBase BBLeafᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞 = {
            .type_id = 39,
            .type_size = 0, 
            .slot_size = 0,
            .tag = __CoreGC::Tag::Value,
            .ptr_mask = nullptr,
            .typekey = "ListOps::BBLeaf<List<(|Nat, Nat|)>>",
            .vtable = nullptr
        };
        struct BBLeafᐸListᐸ丨NatᐧNat丨ᐳᐳ{ 
        };
        static_assert(sizeof(BBLeafᐸListᐸ丨NatᐧNat丨ᐳᐳ) == 1);
        __CoreGC::TypeInfoBase BBLeafᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞 = {
            .type_id = 45,
            .type_size = 0, 
            .slot_size = 0,
            .tag = __CoreGC::Tag::Value,
            .ptr_mask = nullptr,
            .typekey = "ListOps::BBLeaf<Main::Body>",
            .vtable = nullptr
        };
        struct BBLeafᐸMainᘏBodyᐳ{ 
        };
        static_assert(sizeof(BBLeafᐸMainᘏBodyᐳ) == 1);
        enum Leafᐸ丨FloatᐧFloatᐧFloat丨ᐳ_entries : uintptr_t {
            Leafᐸ丨FloatᐧFloatᐧFloat丨ᐳ_v
        };
        const __CoreGC::FieldOffsetInfo Leafᐸ丨FloatᐧFloatᐧFloat丨ᐳ_vtable[] = {
            { 0, Leafᐸ丨FloatᐧFloatᐧFloat丨ᐳ_entries::Leafᐸ丨FloatᐧFloatᐧFloat丨ᐳ_v, 0 }
        };
        __CoreGC::TypeInfoBase Leafᐸ丨FloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞 = {
            .type_id = 13,
            .type_size = 24, 
            .slot_size = 3,
            .tag = __CoreGC::Tag::Value,
            .ptr_mask = "000",
            .typekey = "ListOps::Leaf<(|Float, Float, Float|)>",
            .vtable = nullptr
        };
        struct Leafᐸ丨FloatᐧFloatᐧFloat丨ᐳ{ 
            __CoreCpp::Tuple3<1, 1, 1> v;
        };
        static_assert(sizeof(Leafᐸ丨FloatᐧFloatᐧFloat丨ᐳ) == 24);
        enum Leafᐸ丨NatᐧNat丨ᐳ_entries : uintptr_t {
            Leafᐸ丨NatᐧNat丨ᐳ_v
        };
        const __CoreGC::FieldOffsetInfo Leafᐸ丨NatᐧNat丨ᐳ_vtable[] = {
            { 0, Leafᐸ丨NatᐧNat丨ᐳ_entries::Leafᐸ丨NatᐧNat丨ᐳ_v, 0 }
        };
        __CoreGC::TypeInfoBase Leafᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞 = {
            .type_id = 30,
            .type_size = 16, 
            .slot_size = 2,
            .tag = __CoreGC::Tag::Value,
            .ptr_mask = "00",
            .typekey = "ListOps::Leaf<(|Nat, Nat|)>",
            .vtable = nullptr
        };
        struct Leafᐸ丨NatᐧNat丨ᐳ{ 
            __CoreCpp::Tuple2<1, 1> v;
        };
        static_assert(sizeof(Leafᐸ丨NatᐧNat丨ᐳ) == 16);
        enum LeafᐸFloatᐳ_entries : uintptr_t {
            LeafᐸFloatᐳ_v
        };
        const __CoreGC::FieldOffsetInfo LeafᐸFloatᐳ_vtable[] = {
            { 11, LeafᐸFloatᐳ_entries::LeafᐸFloatᐳ_v, 0 }
        };
        __CoreGC::TypeInfoBase LeafᐸFloatᐳ𝐓𝐲𝐩𝐞 = {
            .type_id = 35,
            .type_size = 8, 
            .slot_size = 1,
            .tag = __CoreGC::Tag::Value,
            .ptr_mask = "0",
            .typekey = "ListOps::Leaf<Float>",
            .vtable = nullptr
        };
        struct LeafᐸFloatᐳ{ 
            __CoreCpp::Float v;
        };
        static_assert(sizeof(LeafᐸFloatᐳ) == 8);
//
// Ref and Tagged Type Definitions
//
        enum Leafᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ_entries : uintptr_t {
            Leafᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ_v
        };
        const __CoreGC::FieldOffsetInfo Leafᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ_vtable[] = {
            { 0, Leafᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ_entries::Leafᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ_v, 0 }
        };
        __CoreGC::TypeInfoBase Leafᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞 = {
            .type_id = 24,
            .type_size = 32, 
            .slot_size = 4,
            .tag = __CoreGC::Tag::Ref,
            .ptr_mask = "1000",
            .typekey = "ListOps::Leaf<(|Main::Body, Float, Float, Float|)>",
            .vtable = nullptr
        };
        struct Leafᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ{ 
            __CoreCpp::Tuple4<1, 1, 1, 1> v;
        };
        static_assert(sizeof(Leafᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ) == 32);
        enum LeafᐸListᐸ丨NatᐧNat丨ᐳᐳ_entries : uintptr_t {
            LeafᐸListᐸ丨NatᐧNat丨ᐳᐳ_v
        };
        const __CoreGC::FieldOffsetInfo LeafᐸListᐸ丨NatᐧNat丨ᐳᐳ_vtable[] = {
            { 40, LeafᐸListᐸ丨NatᐧNat丨ᐳᐳ_entries::LeafᐸListᐸ丨NatᐧNat丨ᐳᐳ_v, 0 }
        };
        __CoreGC::TypeInfoBase LeafᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞 = {
            .type_id = 41,
            .type_size = 24, 
            .slot_size = 3,
            .tag = __CoreGC::Tag::Ref,
            .ptr_mask = "200",
            .typekey = "ListOps::Leaf<List<(|Nat, Nat|)>>",
            .vtable = nullptr
        };
        struct LeafᐸListᐸ丨NatᐧNat丨ᐳᐳ{ 
            Listᐸ丨NatᐧNat丨ᐳ v;
        };
        static_assert(sizeof(LeafᐸListᐸ丨NatᐧNat丨ᐳᐳ) == 24);
        enum LeafᐸMainᘏBodyᐳ_entries : uintptr_t {
            LeafᐸMainᘏBodyᐳ_v
        };
        const __CoreGC::FieldOffsetInfo LeafᐸMainᘏBodyᐳ_vtable[] = {
            { 22, LeafᐸMainᘏBodyᐳ_entries::LeafᐸMainᘏBodyᐳ_v, 0 }
        };
        __CoreGC::TypeInfoBase LeafᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞 = {
            .type_id = 46,
            .type_size = 8, 
            .slot_size = 1,
            .tag = __CoreGC::Tag::Ref,
            .ptr_mask = "1",
            .typekey = "ListOps::Leaf<Main::Body>",
            .vtable = nullptr
        };
        struct LeafᐸMainᘏBodyᐳ{ 
            Main::Body* v;
        };
        static_assert(sizeof(LeafᐸMainᘏBodyᐳ) == 8);
        enum Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ_entries : uintptr_t {
            Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ_c,
            Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ_count,
            Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ_l,
            Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ_r
        };
        const __CoreGC::FieldOffsetInfo Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ_vtable[] = {
            { 9, Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ_entries::Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ_c, 0 },
            { 1, Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ_entries::Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ_count, 8 },
            { 15, Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ_entries::Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ_l, 16 },
            { 15, Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ_entries::Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ_r, 24 }
        };
        __CoreGC::TypeInfoBase Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞 = {
            .type_id = 16,
            .type_size = 80, 
            .slot_size = 10,
            .tag = __CoreGC::Tag::Ref,
            .ptr_mask = "0020002000",
            .typekey = "ListOps::Node<(|Float, Float, Float|)>",
            .vtable = nullptr
        };
        struct Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ{ 
            Color c;
            __CoreCpp::Nat count;
            Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ l;
            Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ r;
        };
        static_assert(sizeof(Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ) == 80);
        enum Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ_entries : uintptr_t {
            Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ_c,
            Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ_count,
            Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ_l,
            Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ_r
        };
        const __CoreGC::FieldOffsetInfo Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ_vtable[] = {
            { 9, Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ_entries::Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ_c, 0 },
            { 1, Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ_entries::Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ_count, 8 },
            { 26, Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ_entries::Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ_l, 16 },
            { 26, Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ_entries::Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ_r, 24 }
        };
        __CoreGC::TypeInfoBase Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞 = {
            .type_id = 27,
            .type_size = 48, 
            .slot_size = 6,
            .tag = __CoreGC::Tag::Ref,
            .ptr_mask = "002020",
            .typekey = "ListOps::Node<(|Main::Body, Float, Float, Float|)>",
            .vtable = nullptr
        };
        struct Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ{ 
            Color c;
            __CoreCpp::Nat count;
            Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ l;
            Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ r;
        };
        static_assert(sizeof(Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ) == 48);
        enum Nodeᐸ丨NatᐧNat丨ᐳ_entries : uintptr_t {
            Nodeᐸ丨NatᐧNat丨ᐳ_c,
            Nodeᐸ丨NatᐧNat丨ᐳ_count,
            Nodeᐸ丨NatᐧNat丨ᐳ_l,
            Nodeᐸ丨NatᐧNat丨ᐳ_r
        };
        const __CoreGC::FieldOffsetInfo Nodeᐸ丨NatᐧNat丨ᐳ_vtable[] = {
            { 9, Nodeᐸ丨NatᐧNat丨ᐳ_entries::Nodeᐸ丨NatᐧNat丨ᐳ_c, 0 },
            { 1, Nodeᐸ丨NatᐧNat丨ᐳ_entries::Nodeᐸ丨NatᐧNat丨ᐳ_count, 8 },
            { 32, Nodeᐸ丨NatᐧNat丨ᐳ_entries::Nodeᐸ丨NatᐧNat丨ᐳ_l, 16 },
            { 32, Nodeᐸ丨NatᐧNat丨ᐳ_entries::Nodeᐸ丨NatᐧNat丨ᐳ_r, 24 }
        };
        __CoreGC::TypeInfoBase Nodeᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞 = {
            .type_id = 33,
            .type_size = 64, 
            .slot_size = 8,
            .tag = __CoreGC::Tag::Ref,
            .ptr_mask = "00200200",
            .typekey = "ListOps::Node<(|Nat, Nat|)>",
            .vtable = nullptr
        };
        struct Nodeᐸ丨NatᐧNat丨ᐳ{ 
            Color c;
            __CoreCpp::Nat count;
            Treeᐸ丨NatᐧNat丨ᐳ l;
            Treeᐸ丨NatᐧNat丨ᐳ r;
        };
        static_assert(sizeof(Nodeᐸ丨NatᐧNat丨ᐳ) == 64);
        enum NodeᐸFloatᐳ_entries : uintptr_t {
            NodeᐸFloatᐳ_c,
            NodeᐸFloatᐳ_count,
            NodeᐸFloatᐳ_l,
            NodeᐸFloatᐳ_r
        };
        const __CoreGC::FieldOffsetInfo NodeᐸFloatᐳ_vtable[] = {
            { 9, NodeᐸFloatᐳ_entries::NodeᐸFloatᐳ_c, 0 },
            { 1, NodeᐸFloatᐳ_entries::NodeᐸFloatᐳ_count, 8 },
            { 37, NodeᐸFloatᐳ_entries::NodeᐸFloatᐳ_l, 16 },
            { 37, NodeᐸFloatᐳ_entries::NodeᐸFloatᐳ_r, 24 }
        };
        __CoreGC::TypeInfoBase NodeᐸFloatᐳ𝐓𝐲𝐩𝐞 = {
            .type_id = 38,
            .type_size = 48, 
            .slot_size = 6,
            .tag = __CoreGC::Tag::Ref,
            .ptr_mask = "002020",
            .typekey = "ListOps::Node<Float>",
            .vtable = nullptr
        };
        struct NodeᐸFloatᐳ{ 
            Color c;
            __CoreCpp::Nat count;
            TreeᐸFloatᐳ l;
            TreeᐸFloatᐳ r;
        };
        static_assert(sizeof(NodeᐸFloatᐳ) == 48);
        enum NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ_entries : uintptr_t {
            NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ_c,
            NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ_count,
            NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ_l,
            NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ_r
        };
        const __CoreGC::FieldOffsetInfo NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ_vtable[] = {
            { 9, NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ_entries::NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ_c, 0 },
            { 1, NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ_entries::NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ_count, 8 },
            { 43, NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ_entries::NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ_l, 16 },
            { 43, NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ_entries::NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ_r, 24 }
        };
        __CoreGC::TypeInfoBase NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞 = {
            .type_id = 44,
            .type_size = 48, 
            .slot_size = 6,
            .tag = __CoreGC::Tag::Ref,
            .ptr_mask = "002020",
            .typekey = "ListOps::Node<List<(|Nat, Nat|)>>",
            .vtable = nullptr
        };
        struct NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ{ 
            Color c;
            __CoreCpp::Nat count;
            TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ l;
            TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ r;
        };
        static_assert(sizeof(NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ) == 48);
        enum NodeᐸMainᘏBodyᐳ_entries : uintptr_t {
            NodeᐸMainᘏBodyᐳ_c,
            NodeᐸMainᘏBodyᐳ_count,
            NodeᐸMainᘏBodyᐳ_l,
            NodeᐸMainᘏBodyᐳ_r
        };
        const __CoreGC::FieldOffsetInfo NodeᐸMainᘏBodyᐳ_vtable[] = {
            { 9, NodeᐸMainᘏBodyᐳ_entries::NodeᐸMainᘏBodyᐳ_c, 0 },
            { 1, NodeᐸMainᘏBodyᐳ_entries::NodeᐸMainᘏBodyᐳ_count, 8 },
            { 48, NodeᐸMainᘏBodyᐳ_entries::NodeᐸMainᘏBodyᐳ_l, 16 },
            { 48, NodeᐸMainᘏBodyᐳ_entries::NodeᐸMainᘏBodyᐳ_r, 24 }
        };
        __CoreGC::TypeInfoBase NodeᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞 = {
            .type_id = 49,
            .type_size = 48, 
            .slot_size = 6,
            .tag = __CoreGC::Tag::Ref,
            .ptr_mask = "002020",
            .typekey = "ListOps::Node<Main::Body>",
            .vtable = nullptr
        };
        struct NodeᐸMainᘏBodyᐳ{ 
            Color c;
            __CoreCpp::Nat count;
            TreeᐸMainᘏBodyᐳ l;
            TreeᐸMainᘏBodyᐳ r;
        };
        static_assert(sizeof(NodeᐸMainᘏBodyᐳ) == 48);
        __CoreGC::TypeInfoBase Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞 = {
            .type_id = 15,
            .type_size = 32, 
            .slot_size = 4,
            .tag = __CoreGC::Tag::Tagged,
            .ptr_mask = "2000",
            .typekey = "ListOps::Tree<(|Float, Float, Float|)>",
            .vtable = nullptr
        };
        __CoreGC::TypeInfoBase Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞 = {
            .type_id = 26,
            .type_size = 16, 
            .slot_size = 2,
            .tag = __CoreGC::Tag::Tagged,
            .ptr_mask = "20",
            .typekey = "ListOps::Tree<(|Main::Body, Float, Float, Float|)>",
            .vtable = nullptr
        };
        __CoreGC::TypeInfoBase Treeᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞 = {
            .type_id = 32,
            .type_size = 24, 
            .slot_size = 3,
            .tag = __CoreGC::Tag::Tagged,
            .ptr_mask = "200",
            .typekey = "ListOps::Tree<(|Nat, Nat|)>",
            .vtable = nullptr
        };
        __CoreGC::TypeInfoBase TreeᐸFloatᐳ𝐓𝐲𝐩𝐞 = {
            .type_id = 37,
            .type_size = 16, 
            .slot_size = 2,
            .tag = __CoreGC::Tag::Tagged,
            .ptr_mask = "20",
            .typekey = "ListOps::Tree<Float>",
            .vtable = nullptr
        };
        __CoreGC::TypeInfoBase TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞 = {
            .type_id = 43,
            .type_size = 16, 
            .slot_size = 2,
            .tag = __CoreGC::Tag::Tagged,
            .ptr_mask = "20",
            .typekey = "ListOps::Tree<List<(|Nat, Nat|)>>",
            .vtable = nullptr
        };
        __CoreGC::TypeInfoBase TreeᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞 = {
            .type_id = 48,
            .type_size = 16, 
            .slot_size = 2,
            .tag = __CoreGC::Tag::Tagged,
            .ptr_mask = "20",
            .typekey = "ListOps::Tree<Main::Body>",
            .vtable = nullptr
        };
//
// All Methods
//
    }
    namespace NumericOps {
//
// Value Type Definitions
//
//
// Ref and Tagged Type Definitions
//
//
// All Methods
//
    }
}
namespace Main {
//
// Value Type Definitions
//
    enum Position_entries : uintptr_t {
        Position_x,
        Position_y,
        Position_z
    };
    const __CoreGC::FieldOffsetInfo Position_vtable[] = {
        { 11, Position_entries::Position_x, 0 },
        { 11, Position_entries::Position_y, 8 },
        { 11, Position_entries::Position_z, 16 }
    };
    __CoreGC::TypeInfoBase Position𝐓𝐲𝐩𝐞 = {
        .type_id = 20,
        .type_size = 24, 
        .slot_size = 3,
        .tag = __CoreGC::Tag::Value,
        .ptr_mask = "000",
        .typekey = "Main::Position",
        .vtable = nullptr
    };
    struct Position { 
        __CoreCpp::Float x;
        __CoreCpp::Float y;
        __CoreCpp::Float z;
    };
    static_assert(sizeof(Position) == 24);
    enum Velocity_entries : uintptr_t {
        Velocity_vx,
        Velocity_vy,
        Velocity_vz
    };
    const __CoreGC::FieldOffsetInfo Velocity_vtable[] = {
        { 11, Velocity_entries::Velocity_vx, 0 },
        { 11, Velocity_entries::Velocity_vy, 8 },
        { 11, Velocity_entries::Velocity_vz, 16 }
    };
    __CoreGC::TypeInfoBase Velocity𝐓𝐲𝐩𝐞 = {
        .type_id = 21,
        .type_size = 24, 
        .slot_size = 3,
        .tag = __CoreGC::Tag::Value,
        .ptr_mask = "000",
        .typekey = "Main::Velocity",
        .vtable = nullptr
    };
    struct Velocity { 
        __CoreCpp::Float vx;
        __CoreCpp::Float vy;
        __CoreCpp::Float vz;
    };
    static_assert(sizeof(Velocity) == 24);
//
// Ref and Tagged Type Definitions
//
    enum Body_entries : uintptr_t {
        Body_name,
        Body_mass,
        Body_pos,
        Body_vel
    };
    const __CoreGC::FieldOffsetInfo Body_vtable[] = {
        { 19, Body_entries::Body_name, 0 },
        { 11, Body_entries::Body_mass, 8 },
        { 20, Body_entries::Body_pos, 16 },
        { 21, Body_entries::Body_vel, 24 }
    };
    __CoreGC::TypeInfoBase Body𝐓𝐲𝐩𝐞 = {
        .type_id = 22,
        .type_size = 80, 
        .slot_size = 10,
        .tag = __CoreGC::Tag::Ref,
        .ptr_mask = "2000000000",
        .typekey = "Main::Body",
        .vtable = nullptr
    };
    struct Body { 
        Core::CString name;
        __CoreCpp::Float mass;
        Position pos;
        Velocity vel;
    };
    static_assert(sizeof(Body) == 80);
    enum NBodySystem_entries : uintptr_t {
        NBodySystem_bodies
    };
    const __CoreGC::FieldOffsetInfo NBodySystem_vtable[] = {
        { 56, NBodySystem_entries::NBodySystem_bodies, 0 }
    };
    __CoreGC::TypeInfoBase NBodySystem𝐓𝐲𝐩𝐞 = {
        .type_id = 57,
        .type_size = 16, 
        .slot_size = 2,
        .tag = __CoreGC::Tag::Ref,
        .ptr_mask = "20",
        .typekey = "Main::NBodySystem",
        .vtable = nullptr
    };
    struct NBodySystem { 
        Core::ListᐸMainᘏBodyᐳ bodies;
    };
    static_assert(sizeof(NBodySystem) == 16);
//
// All Methods
//
    Body* BodyᘏoffsetMomentum([[maybe_unused]] Body* 𝐭𝐡𝐢𝐬, __CoreCpp::Float px, __CoreCpp::Float py, __CoreCpp::Float pz) noexcept;
    __CoreCpp::Float BodyᘏkineticEnergy([[maybe_unused]] Body* 𝐭𝐡𝐢𝐬) noexcept;
    __CoreCpp::Float NBodySystemᘏpotentialEnergyCompute([[maybe_unused]] NBodySystem* 𝐭𝐡𝐢𝐬, Core::Listᐸ丨NatᐧNat丨ᐳ ppairs) noexcept;
    __CoreCpp::Float NBodySystemᘏenergy([[maybe_unused]] NBodySystem* 𝐭𝐡𝐢𝐬) noexcept;
    NBodySystem* NBodySystemᘏadvance([[maybe_unused]] NBodySystem* 𝐭𝐡𝐢𝐬, __CoreCpp::Float dt) noexcept;
}
//
// Namespace/Type Function Forward Declarations
//
namespace Core {
    namespace Algorithm {
        template <typename λpred_丨CCharBufferᐧCCharBuffer丨_$Bool_guard, typename λfn_丨CCharBufferᐧCCharBuffer丨_$丨CCharBufferᐧCCharBuffer丨_op>
        __CoreCpp::Tuple2<2, 2> whileᐸ丨CCharBufferᐧCCharBuffer丨ᐳ(__CoreCpp::Tuple2<2, 2> s, λpred_丨CCharBufferᐧCCharBuffer丨_$Bool_guard&& guard, λfn_丨CCharBufferᐧCCharBuffer丨_$丨CCharBufferᐧCCharBuffer丨_op&& op) noexcept;
    }
    namespace CCharBufferOps {
        __CoreCpp::Bool equal(__CoreCpp::CCharBuffer cb1, __CoreCpp::CCharBuffer cb2) noexcept;
        __CoreCpp::Nat getMaxSize() noexcept;
        __CoreCpp::Bool less(__CoreCpp::CCharBuffer cb1, __CoreCpp::CCharBuffer cb2) noexcept;
        __CoreCpp::CCharBuffer mergeCBuffers(__CoreCpp::CCharBuffer cb1, __CoreCpp::CCharBuffer cb2) noexcept;
        __CoreCpp::Tuple2<2, 2> mergeCBuffers2(__CoreCpp::CCharBuffer cb1, __CoreCpp::CCharBuffer cb2) noexcept;
        __CoreCpp::CCharBuffer remainder(__CoreCpp::CCharBuffer cb, __CoreCpp::Nat split) noexcept;
        __CoreCpp::Nat size(__CoreCpp::CCharBuffer cb) noexcept;
    }
    namespace CRopeOps {
        Rope append(Rope r, __CoreCpp::CCharBuffer v) noexcept;
        Rope append_helper(Rope r, __CoreCpp::CCharBuffer v) noexcept;
        Rope balance(Color c, Rope tleft, Rope tright) noexcept;
        OptionᐸCRopeOpsᘏNodeᐳ balanceHelper_DB_L(Color c, Rope tleft, Rope tright) noexcept;
        OptionᐸCRopeOpsᘏNodeᐳ balanceHelper_DB_R(Color c, Rope tleft, Rope tright) noexcept;
        OptionᐸCRopeOpsᘏNodeᐳ balanceHelper_RR_LL(Color c, Rope tleft, Rope tright) noexcept;
        OptionᐸCRopeOpsᘏNodeᐳ balanceHelper_RR_LR(Color c, Rope tleft, Rope tright) noexcept;
        OptionᐸCRopeOpsᘏNodeᐳ balanceHelper_RR_RL(Color c, Rope tleft, Rope tright) noexcept;
        OptionᐸCRopeOpsᘏNodeᐳ balanceHelper_RR_RR(Color c, Rope tleft, Rope tright) noexcept;
        __CoreCpp::Bool equal(Rope r1, Rope r2) noexcept;
        __CoreCpp::Nat length(Rope r) noexcept;
        __CoreCpp::Bool less(Rope r1, Rope r2) noexcept;
        Color redden(Color c) noexcept;
        CRope s_crope_append(CRope r, __CoreCpp::CCharBuffer buf) noexcept;
        CRope s_crope_create(__CoreCpp::CCharBuffer buf) noexcept;
        __CoreCpp::Bool s_crope_equal(CRope cr1, CRope cr2) noexcept;
        __CoreCpp::Bool s_crope_less(CRope cr1, CRope cr2) noexcept;
        Leaf RopeᘏcreateLeaf(__CoreCpp::CCharBuffer buf) noexcept;
        Node* RopeᘏcreateNode(Color c, Rope l, Rope r) noexcept;
        __CoreCpp::Nat RopeᘏgetCharacterCount(Rope rope) noexcept;
    }
    namespace ListOps {
        Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ balanceᐸ丨FloatᐧFloatᐧFloat丨ᐳ(Color c, Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ tleft, Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ tright) noexcept;
        Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ balanceᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ(Color c, Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ tleft, Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ tright) noexcept;
        Treeᐸ丨NatᐧNat丨ᐳ balanceᐸ丨NatᐧNat丨ᐳ(Color c, Treeᐸ丨NatᐧNat丨ᐳ tleft, Treeᐸ丨NatᐧNat丨ᐳ tright) noexcept;
        TreeᐸFloatᐳ balanceᐸFloatᐳ(Color c, TreeᐸFloatᐳ tleft, TreeᐸFloatᐳ tright) noexcept;
        TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ balanceᐸListᐸ丨NatᐧNat丨ᐳᐳ(Color c, TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ tleft, TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ tright) noexcept;
        TreeᐸMainᘏBodyᐳ balanceᐸMainᘏBodyᐳ(Color c, TreeᐸMainᘏBodyᐳ tleft, TreeᐸMainᘏBodyᐳ tright) noexcept;
        OptionᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ balanceHelper_DB_Lᐸ丨FloatᐧFloatᐧFloat丨ᐳ(Color c, Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ tleft, Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ tright) noexcept;
        OptionᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ balanceHelper_DB_Lᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ(Color c, Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ tleft, Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ tright) noexcept;
        OptionᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ balanceHelper_DB_Lᐸ丨NatᐧNat丨ᐳ(Color c, Treeᐸ丨NatᐧNat丨ᐳ tleft, Treeᐸ丨NatᐧNat丨ᐳ tright) noexcept;
        OptionᐸListOpsᘏNodeᐸFloatᐳᐳ balanceHelper_DB_LᐸFloatᐳ(Color c, TreeᐸFloatᐳ tleft, TreeᐸFloatᐳ tright) noexcept;
        OptionᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ balanceHelper_DB_LᐸListᐸ丨NatᐧNat丨ᐳᐳ(Color c, TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ tleft, TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ tright) noexcept;
        OptionᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ balanceHelper_DB_LᐸMainᘏBodyᐳ(Color c, TreeᐸMainᘏBodyᐳ tleft, TreeᐸMainᘏBodyᐳ tright) noexcept;
        OptionᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ balanceHelper_DB_Rᐸ丨FloatᐧFloatᐧFloat丨ᐳ(Color c, Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ tleft, Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ tright) noexcept;
        OptionᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ balanceHelper_DB_Rᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ(Color c, Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ tleft, Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ tright) noexcept;
        OptionᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ balanceHelper_DB_Rᐸ丨NatᐧNat丨ᐳ(Color c, Treeᐸ丨NatᐧNat丨ᐳ tleft, Treeᐸ丨NatᐧNat丨ᐳ tright) noexcept;
        OptionᐸListOpsᘏNodeᐸFloatᐳᐳ balanceHelper_DB_RᐸFloatᐳ(Color c, TreeᐸFloatᐳ tleft, TreeᐸFloatᐳ tright) noexcept;
        OptionᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ balanceHelper_DB_RᐸListᐸ丨NatᐧNat丨ᐳᐳ(Color c, TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ tleft, TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ tright) noexcept;
        OptionᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ balanceHelper_DB_RᐸMainᘏBodyᐳ(Color c, TreeᐸMainᘏBodyᐳ tleft, TreeᐸMainᘏBodyᐳ tright) noexcept;
        OptionᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ balanceHelper_RR_LLᐸ丨FloatᐧFloatᐧFloat丨ᐳ(Color c, Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ tleft, Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ tright) noexcept;
        OptionᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ balanceHelper_RR_LLᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ(Color c, Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ tleft, Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ tright) noexcept;
        OptionᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ balanceHelper_RR_LLᐸ丨NatᐧNat丨ᐳ(Color c, Treeᐸ丨NatᐧNat丨ᐳ tleft, Treeᐸ丨NatᐧNat丨ᐳ tright) noexcept;
        OptionᐸListOpsᘏNodeᐸFloatᐳᐳ balanceHelper_RR_LLᐸFloatᐳ(Color c, TreeᐸFloatᐳ tleft, TreeᐸFloatᐳ tright) noexcept;
        OptionᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ balanceHelper_RR_LLᐸListᐸ丨NatᐧNat丨ᐳᐳ(Color c, TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ tleft, TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ tright) noexcept;
        OptionᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ balanceHelper_RR_LLᐸMainᘏBodyᐳ(Color c, TreeᐸMainᘏBodyᐳ tleft, TreeᐸMainᘏBodyᐳ tright) noexcept;
        OptionᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ balanceHelper_RR_LRᐸ丨FloatᐧFloatᐧFloat丨ᐳ(Color c, Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ tleft, Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ tright) noexcept;
        OptionᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ balanceHelper_RR_LRᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ(Color c, Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ tleft, Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ tright) noexcept;
        OptionᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ balanceHelper_RR_LRᐸ丨NatᐧNat丨ᐳ(Color c, Treeᐸ丨NatᐧNat丨ᐳ tleft, Treeᐸ丨NatᐧNat丨ᐳ tright) noexcept;
        OptionᐸListOpsᘏNodeᐸFloatᐳᐳ balanceHelper_RR_LRᐸFloatᐳ(Color c, TreeᐸFloatᐳ tleft, TreeᐸFloatᐳ tright) noexcept;
        OptionᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ balanceHelper_RR_LRᐸListᐸ丨NatᐧNat丨ᐳᐳ(Color c, TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ tleft, TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ tright) noexcept;
        OptionᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ balanceHelper_RR_LRᐸMainᘏBodyᐳ(Color c, TreeᐸMainᘏBodyᐳ tleft, TreeᐸMainᘏBodyᐳ tright) noexcept;
        OptionᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ balanceHelper_RR_RLᐸ丨FloatᐧFloatᐧFloat丨ᐳ(Color c, Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ tleft, Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ tright) noexcept;
        OptionᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ balanceHelper_RR_RLᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ(Color c, Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ tleft, Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ tright) noexcept;
        OptionᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ balanceHelper_RR_RLᐸ丨NatᐧNat丨ᐳ(Color c, Treeᐸ丨NatᐧNat丨ᐳ tleft, Treeᐸ丨NatᐧNat丨ᐳ tright) noexcept;
        OptionᐸListOpsᘏNodeᐸFloatᐳᐳ balanceHelper_RR_RLᐸFloatᐳ(Color c, TreeᐸFloatᐳ tleft, TreeᐸFloatᐳ tright) noexcept;
        OptionᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ balanceHelper_RR_RLᐸListᐸ丨NatᐧNat丨ᐳᐳ(Color c, TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ tleft, TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ tright) noexcept;
        OptionᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ balanceHelper_RR_RLᐸMainᘏBodyᐳ(Color c, TreeᐸMainᘏBodyᐳ tleft, TreeᐸMainᘏBodyᐳ tright) noexcept;
        OptionᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ balanceHelper_RR_RRᐸ丨FloatᐧFloatᐧFloat丨ᐳ(Color c, Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ tleft, Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ tright) noexcept;
        OptionᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ balanceHelper_RR_RRᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ(Color c, Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ tleft, Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ tright) noexcept;
        OptionᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ balanceHelper_RR_RRᐸ丨NatᐧNat丨ᐳ(Color c, Treeᐸ丨NatᐧNat丨ᐳ tleft, Treeᐸ丨NatᐧNat丨ᐳ tright) noexcept;
        OptionᐸListOpsᘏNodeᐸFloatᐳᐳ balanceHelper_RR_RRᐸFloatᐳ(Color c, TreeᐸFloatᐳ tleft, TreeᐸFloatᐳ tright) noexcept;
        OptionᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ balanceHelper_RR_RRᐸListᐸ丨NatᐧNat丨ᐳᐳ(Color c, TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ tleft, TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ tright) noexcept;
        OptionᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ balanceHelper_RR_RRᐸMainᘏBodyᐳ(Color c, TreeᐸMainᘏBodyᐳ tleft, TreeᐸMainᘏBodyᐳ tright) noexcept;
        Main::Body* getᐸMainᘏBodyᐳ(TreeᐸMainᘏBodyᐳ t, __CoreCpp::Nat idx) noexcept;
        Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ pushBackᐸ丨FloatᐧFloatᐧFloat丨ᐳ(Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ t, __CoreCpp::Tuple3<1, 1, 1> v) noexcept;
        Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ pushBackᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ(Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ t, __CoreCpp::Tuple4<1, 1, 1, 1> v) noexcept;
        Treeᐸ丨NatᐧNat丨ᐳ pushBackᐸ丨NatᐧNat丨ᐳ(Treeᐸ丨NatᐧNat丨ᐳ t, __CoreCpp::Tuple2<1, 1> v) noexcept;
        TreeᐸFloatᐳ pushBackᐸFloatᐳ(TreeᐸFloatᐳ t, __CoreCpp::Float v) noexcept;
        TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ pushBackᐸListᐸ丨NatᐧNat丨ᐳᐳ(TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ t, Listᐸ丨NatᐧNat丨ᐳ v) noexcept;
        TreeᐸMainᘏBodyᐳ pushBackᐸMainᘏBodyᐳ(TreeᐸMainᘏBodyᐳ t, Main::Body* v) noexcept;
        Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ pushBack_helperᐸ丨FloatᐧFloatᐧFloat丨ᐳ(Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ t, __CoreCpp::Tuple3<1, 1, 1> v) noexcept;
        Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ pushBack_helperᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ(Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ t, __CoreCpp::Tuple4<1, 1, 1, 1> v) noexcept;
        Treeᐸ丨NatᐧNat丨ᐳ pushBack_helperᐸ丨NatᐧNat丨ᐳ(Treeᐸ丨NatᐧNat丨ᐳ t, __CoreCpp::Tuple2<1, 1> v) noexcept;
        TreeᐸFloatᐳ pushBack_helperᐸFloatᐳ(TreeᐸFloatᐳ t, __CoreCpp::Float v) noexcept;
        TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ pushBack_helperᐸListᐸ丨NatᐧNat丨ᐳᐳ(TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ t, Listᐸ丨NatᐧNat丨ᐳ v) noexcept;
        TreeᐸMainᘏBodyᐳ pushBack_helperᐸMainᘏBodyᐳ(TreeᐸMainᘏBodyᐳ t, Main::Body* v) noexcept;
        Color redden(Color c) noexcept;
        Listᐸ丨NatᐧNat丨ᐳ s_list_create_1ᐸ丨NatᐧNat丨ᐳ(__CoreCpp::Tuple2<1, 1> v1) noexcept;
        Listᐸ丨NatᐧNat丨ᐳ s_list_create_2ᐸ丨NatᐧNat丨ᐳ(__CoreCpp::Tuple2<1, 1> v1, __CoreCpp::Tuple2<1, 1> v2) noexcept;
        Listᐸ丨NatᐧNat丨ᐳ s_list_create_3ᐸ丨NatᐧNat丨ᐳ(__CoreCpp::Tuple2<1, 1> v1, __CoreCpp::Tuple2<1, 1> v2, __CoreCpp::Tuple2<1, 1> v3) noexcept;
        Listᐸ丨NatᐧNat丨ᐳ s_list_create_4ᐸ丨NatᐧNat丨ᐳ(__CoreCpp::Tuple2<1, 1> v1, __CoreCpp::Tuple2<1, 1> v2, __CoreCpp::Tuple2<1, 1> v3, __CoreCpp::Tuple2<1, 1> v4) noexcept;
        ListᐸListᐸ丨NatᐧNat丨ᐳᐳ s_list_create_4ᐸListᐸ丨NatᐧNat丨ᐳᐳ(Listᐸ丨NatᐧNat丨ᐳ v1, Listᐸ丨NatᐧNat丨ᐳ v2, Listᐸ丨NatᐧNat丨ᐳ v3, Listᐸ丨NatᐧNat丨ᐳ v4) noexcept;
        ListᐸMainᘏBodyᐳ s_list_create_4ᐸMainᘏBodyᐳ(Main::Body* v1, Main::Body* v2, Main::Body* v3, Main::Body* v4) noexcept;
        ListᐸMainᘏBodyᐳ s_list_create_5ᐸMainᘏBodyᐳ(Main::Body* v1, Main::Body* v2, Main::Body* v3, Main::Body* v4, Main::Body* v5) noexcept;
        Listᐸ丨FloatᐧFloatᐧFloat丨ᐳ s_list_create_emptyᐸ丨FloatᐧFloatᐧFloat丨ᐳ() noexcept;
        Listᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ s_list_create_emptyᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ() noexcept;
        Listᐸ丨NatᐧNat丨ᐳ s_list_create_emptyᐸ丨NatᐧNat丨ᐳ() noexcept;
        ListᐸFloatᐳ s_list_create_emptyᐸFloatᐳ() noexcept;
        ListᐸListᐸ丨NatᐧNat丨ᐳᐳ s_list_create_emptyᐸListᐸ丨NatᐧNat丨ᐳᐳ() noexcept;
        ListᐸMainᘏBodyᐳ s_list_create_emptyᐸMainᘏBodyᐳ() noexcept;
        __CoreCpp::Bool s_list_emptyᐸ丨FloatᐧFloatᐧFloat丨ᐳ(Listᐸ丨FloatᐧFloatᐧFloat丨ᐳ l) noexcept;
        __CoreCpp::Bool s_list_emptyᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ(Listᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ l) noexcept;
        __CoreCpp::Bool s_list_emptyᐸ丨NatᐧNat丨ᐳ(Listᐸ丨NatᐧNat丨ᐳ l) noexcept;
        __CoreCpp::Bool s_list_emptyᐸFloatᐳ(ListᐸFloatᐳ l) noexcept;
        __CoreCpp::Bool s_list_emptyᐸListᐸ丨NatᐧNat丨ᐳᐳ(ListᐸListᐸ丨NatᐧNat丨ᐳᐳ l) noexcept;
        __CoreCpp::Bool s_list_emptyᐸMainᘏBodyᐳ(ListᐸMainᘏBodyᐳ l) noexcept;
        Main::Body* s_list_getᐸMainᘏBodyᐳ(ListᐸMainᘏBodyᐳ l, __CoreCpp::Nat idx) noexcept;
        template <typename λfn_丨FloatᐧFloatᐧFloat丨_$Float_f>
        ListᐸFloatᐳ s_list_mapᐸ丨FloatᐧFloatᐧFloat丨ᐧFloatᐳ(Listᐸ丨FloatᐧFloatᐧFloat丨ᐳ l, λfn_丨FloatᐧFloatᐧFloat丨_$Float_f&& f) noexcept;
        template <typename λfn_丨BodyᐧFloatᐧFloatᐧFloat丨_$MainᘏBody_f>
        ListᐸMainᘏBodyᐳ s_list_mapᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐧMainᘏBodyᐳ(Listᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ l, λfn_丨BodyᐧFloatᐧFloatᐧFloat丨_$MainᘏBody_f&& f) noexcept;
        template <typename λfn_丨NatᐧNat丨_$Float_f>
        ListᐸFloatᐳ s_list_mapᐸ丨NatᐧNat丨ᐧFloatᐳ(Listᐸ丨NatᐧNat丨ᐳ l, λfn_丨NatᐧNat丨_$Float_f&& f) noexcept;
        template <typename λfn_Listᐸ丨NatᐧNat丨ᐳ_$Float_f>
        ListᐸFloatᐳ s_list_mapᐸListᐸ丨NatᐧNat丨ᐳᐧFloatᐳ(ListᐸListᐸ丨NatᐧNat丨ᐳᐳ l, λfn_Listᐸ丨NatᐧNat丨ᐳ_$Float_f&& f) noexcept;
        template <typename λfn_Body_$丨FloatᐧFloatᐧFloat丨_f>
        Listᐸ丨FloatᐧFloatᐧFloat丨ᐳ s_list_mapᐸMainᘏBodyᐧ丨FloatᐧFloatᐧFloat丨ᐳ(ListᐸMainᘏBodyᐳ l, λfn_Body_$丨FloatᐧFloatᐧFloat丨_f&& f) noexcept;
        template <typename λfn_Body_$丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨_f>
        Listᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ s_list_mapᐸMainᘏBodyᐧ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ(ListᐸMainᘏBodyᐳ l, λfn_Body_$丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨_f&& f) noexcept;
        template <typename λfn_Body_$Float_f>
        ListᐸFloatᐳ s_list_mapᐸMainᘏBodyᐧFloatᐳ(ListᐸMainᘏBodyᐳ l, λfn_Body_$Float_f&& f) noexcept;
        Listᐸ丨FloatᐧFloatᐧFloat丨ᐳ s_list_push_backᐸ丨FloatᐧFloatᐧFloat丨ᐳ(Listᐸ丨FloatᐧFloatᐧFloat丨ᐳ l, __CoreCpp::Tuple3<1, 1, 1> v) noexcept;
        Listᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ s_list_push_backᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ(Listᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ l, __CoreCpp::Tuple4<1, 1, 1, 1> v) noexcept;
        Listᐸ丨NatᐧNat丨ᐳ s_list_push_backᐸ丨NatᐧNat丨ᐳ(Listᐸ丨NatᐧNat丨ᐳ l, __CoreCpp::Tuple2<1, 1> v) noexcept;
        ListᐸFloatᐳ s_list_push_backᐸFloatᐳ(ListᐸFloatᐳ l, __CoreCpp::Float v) noexcept;
        ListᐸListᐸ丨NatᐧNat丨ᐳᐳ s_list_push_backᐸListᐸ丨NatᐧNat丨ᐳᐳ(ListᐸListᐸ丨NatᐧNat丨ᐳᐳ l, Listᐸ丨NatᐧNat丨ᐳ v) noexcept;
        ListᐸMainᘏBodyᐳ s_list_push_backᐸMainᘏBodyᐳ(ListᐸMainᘏBodyᐳ l, Main::Body* v) noexcept;
        __CoreCpp::Nat s_list_sizeᐸMainᘏBodyᐳ(ListᐸMainᘏBodyᐳ l) noexcept;
        __CoreCpp::Float s_list_sumᐸFloatᐳ(ListᐸFloatᐳ l, __CoreCpp::Float zero) noexcept;
        __CoreCpp::Nat sizeᐸ丨FloatᐧFloatᐧFloat丨ᐳ(Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ t) noexcept;
        __CoreCpp::Nat sizeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ(Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ t) noexcept;
        __CoreCpp::Nat sizeᐸ丨NatᐧNat丨ᐳ(Treeᐸ丨NatᐧNat丨ᐳ t) noexcept;
        __CoreCpp::Nat sizeᐸFloatᐳ(TreeᐸFloatᐳ t) noexcept;
        __CoreCpp::Nat sizeᐸListᐸ丨NatᐧNat丨ᐳᐳ(TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ t) noexcept;
        __CoreCpp::Nat sizeᐸMainᘏBodyᐳ(TreeᐸMainᘏBodyᐳ t) noexcept;
        Leafᐸ丨FloatᐧFloatᐧFloat丨ᐳ Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳᘏcreateLeaf(__CoreCpp::Tuple3<1, 1, 1> v) noexcept;
        Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ* Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳᘏcreateNode(Color c, Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ l, Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ r) noexcept;
        template <typename λfn_丨FloatᐧFloatᐧFloat丨_$Float_f>
        TreeᐸFloatᐳ Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳᘏmapᐸFloatᐳ(Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ t, λfn_丨FloatᐧFloatᐧFloat丨_$Float_f&& f) noexcept;
        Leafᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ* Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᘏcreateLeaf(__CoreCpp::Tuple4<1, 1, 1, 1> v) noexcept;
        Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ* Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᘏcreateNode(Color c, Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ l, Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ r) noexcept;
        template <typename λfn_丨BodyᐧFloatᐧFloatᐧFloat丨_$MainᘏBody_f>
        TreeᐸMainᘏBodyᐳ Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᘏmapᐸMainᘏBodyᐳ(Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ t, λfn_丨BodyᐧFloatᐧFloatᐧFloat丨_$MainᘏBody_f&& f) noexcept;
        Leafᐸ丨NatᐧNat丨ᐳ Treeᐸ丨NatᐧNat丨ᐳᘏcreateLeaf(__CoreCpp::Tuple2<1, 1> v) noexcept;
        Nodeᐸ丨NatᐧNat丨ᐳ* Treeᐸ丨NatᐧNat丨ᐳᘏcreateNode(Color c, Treeᐸ丨NatᐧNat丨ᐳ l, Treeᐸ丨NatᐧNat丨ᐳ r) noexcept;
        template <typename λfn_丨NatᐧNat丨_$Float_f>
        TreeᐸFloatᐳ Treeᐸ丨NatᐧNat丨ᐳᘏmapᐸFloatᐳ(Treeᐸ丨NatᐧNat丨ᐳ t, λfn_丨NatᐧNat丨_$Float_f&& f) noexcept;
        LeafᐸFloatᐳ TreeᐸFloatᐳᘏcreateLeaf(__CoreCpp::Float v) noexcept;
        NodeᐸFloatᐳ* TreeᐸFloatᐳᘏcreateNode(Color c, TreeᐸFloatᐳ l, TreeᐸFloatᐳ r) noexcept;
        __CoreCpp::Float TreeᐸFloatᐳᘏsum(TreeᐸFloatᐳ t, __CoreCpp::Float acc) noexcept;
        LeafᐸListᐸ丨NatᐧNat丨ᐳᐳ* TreeᐸListᐸ丨NatᐧNat丨ᐳᐳᘏcreateLeaf(Listᐸ丨NatᐧNat丨ᐳ v) noexcept;
        NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ* TreeᐸListᐸ丨NatᐧNat丨ᐳᐳᘏcreateNode(Color c, TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ l, TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ r) noexcept;
        template <typename λfn_Listᐸ丨NatᐧNat丨ᐳ_$Float_f>
        TreeᐸFloatᐳ TreeᐸListᐸ丨NatᐧNat丨ᐳᐳᘏmapᐸFloatᐳ(TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ t, λfn_Listᐸ丨NatᐧNat丨ᐳ_$Float_f&& f) noexcept;
        LeafᐸMainᘏBodyᐳ* TreeᐸMainᘏBodyᐳᘏcreateLeaf(Main::Body* v) noexcept;
        NodeᐸMainᘏBodyᐳ* TreeᐸMainᘏBodyᐳᘏcreateNode(Color c, TreeᐸMainᘏBodyᐳ l, TreeᐸMainᘏBodyᐳ r) noexcept;
        template <typename λfn_Body_$丨FloatᐧFloatᐧFloat丨_f>
        Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ TreeᐸMainᘏBodyᐳᘏmapᐸ丨FloatᐧFloatᐧFloat丨ᐳ(TreeᐸMainᘏBodyᐳ t, λfn_Body_$丨FloatᐧFloatᐧFloat丨_f&& f) noexcept;
        template <typename λfn_Body_$丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨_f>
        Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ TreeᐸMainᘏBodyᐳᘏmapᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ(TreeᐸMainᘏBodyᐳ t, λfn_Body_$丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨_f&& f) noexcept;
        template <typename λfn_Body_$Float_f>
        TreeᐸFloatᐳ TreeᐸMainᘏBodyᐳᘏmapᐸFloatᐳ(TreeᐸMainᘏBodyᐳ t, λfn_Body_$Float_f&& f) noexcept;
    }
    namespace NumericOps {
        __CoreCpp::Float s_floatSqrt(__CoreCpp::Float a) noexcept;
    }
    CRopeIterator CRopeIteratorᘏinitialize(CRopeOps::Rope r) noexcept;
    __CoreCpp::Float Floatᘏsqrt(__CoreCpp::Float x) noexcept;
    __CoreCpp::Float Floatᘏsquare(__CoreCpp::Float x) noexcept;
}
namespace Main {
    __CoreCpp::Float main() noexcept;
    __CoreCpp::Float Bodyᘏdistance(Body* b0, Body* b1) noexcept;
    NBodySystem* NBodySystemᘏcreate() noexcept;
}
__CoreCpp::Bool operator==(const Core::CString& lhs, const Core::CString& rhs) { return Core::CRopeOps::s_crope_equal(lhs, rhs); }
__CoreCpp::Bool operator<(const Core::CString& lhs, const Core::CString& rhs) { return Core::CRopeOps::s_crope_less(lhs, rhs); }
