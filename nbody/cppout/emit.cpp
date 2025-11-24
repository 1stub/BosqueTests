#include "emit.hpp"

GCAllocator alloc3(24, REAL_ENTRY_SIZE(24), collect);
GCAllocator alloc4(32, REAL_ENTRY_SIZE(32), collect);
GCAllocator alloc2(16, REAL_ENTRY_SIZE(16), collect);
GCAllocator alloc1(8, REAL_ENTRY_SIZE(8), collect);
GCAllocator alloc8(64, REAL_ENTRY_SIZE(64), collect);
GCAllocator alloc10(80, REAL_ENTRY_SIZE(80), collect);
GCAllocator alloc6(48, REAL_ENTRY_SIZE(48), collect);
GCAllocator* allocs[7] = {&alloc3, &alloc4, &alloc2, &alloc1, &alloc8, &alloc10, &alloc6};

//
// Emitted Functions/Methods
//
namespace Core {
    namespace Algorithm {
//
// Constants
//
//
// Constants
//
        template <typename λpred_丨CCharBufferᐧCCharBuffer丨_$Bool_guard, typename λfn_丨CCharBufferᐧCCharBuffer丨_$丨CCharBufferᐧCCharBuffer丨_op>
        __CoreCpp::Tuple2<2, 2> whileᐸ丨CCharBufferᐧCCharBuffer丨ᐳ(__CoreCpp::Tuple2<2, 2> s, λpred_丨CCharBufferᐧCCharBuffer丨_$Bool_guard&& guard, λfn_丨CCharBufferᐧCCharBuffer丨_$丨CCharBufferᐧCCharBuffer丨_op&& op) noexcept  {
            return 𝐰𝐡𝐢𝐥𝐞(s, guard, op);
        }
    }
    namespace CCharBufferOps {
//
// Constants
//
//
// Constants
//
        __CoreCpp::Bool equal(__CoreCpp::CCharBuffer cb1, __CoreCpp::CCharBuffer cb2) noexcept  {
            return __CoreCpp::cbufferEqual(cb1, cb2);
        }
        __CoreCpp::Nat getMaxSize() noexcept  {
            return __CoreCpp::Nat(__CoreCpp::maxCCharBufferSize);
        }
        __CoreCpp::Bool less(__CoreCpp::CCharBuffer cb1, __CoreCpp::CCharBuffer cb2) noexcept  {
            return __CoreCpp::cbufferLess(cb1, cb2);
        }
        __CoreCpp::CCharBuffer mergeCBuffers(__CoreCpp::CCharBuffer cb1, __CoreCpp::CCharBuffer cb2) noexcept  {
            return __CoreCpp::cbufferMerge(cb1, cb2);
        }
        __CoreCpp::Tuple2<2, 2> mergeCBuffers2(__CoreCpp::CCharBuffer cb1, __CoreCpp::CCharBuffer cb2) noexcept  {
            __CoreCpp::Nat cb1size = (getMaxSize() - CCharBufferᘏsize(cb1));
            __CoreCpp::CCharBuffer ncb1 = mergeCBuffers(cb1, cb2);
            __CoreCpp::CCharBuffer ncb2 = remainder(cb2, cb1size);
            return __CoreCpp::Tuple2<2, 2>(ncb1, ncb2);
        }
        __CoreCpp::CCharBuffer remainder(__CoreCpp::CCharBuffer cb, __CoreCpp::Nat split) noexcept  {
            return __CoreCpp::cbufferRemainder(cb, split);
        }
        __CoreCpp::Nat size(__CoreCpp::CCharBuffer cb) noexcept  {
            return cb.size;
        }
    }
    namespace CRopeOps {
//
// Constants
//
        inline Rope RopeᘏemptyRope();
//
// Constants
//
        inline Rope RopeᘏemptyRope() { return Rope( &BBLeaf𝐓𝐲𝐩𝐞 ); }
        Rope append(Rope r, __CoreCpp::CCharBuffer v) noexcept  {
            if( r.typeinfo == &BBLeaf𝐓𝐲𝐩𝐞 ) {
                return Rope( &Leaf𝐓𝐲𝐩𝐞, RopeᘏcreateLeaf(v) );
            }
            Rope nr = append_helper(r, v);
            if( nr.typeinfo != &Node𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Rope $nr = nr; 
                return nr;
            }
            else {
                [[maybe_unused]] Node* $nr = nr.template access<Node*>(); 
                return Rope( &Node𝐓𝐲𝐩𝐞, ( ($nr->c == Color::Red) ? (RopeᘏcreateNode(Color::Black, $nr->l, $nr->r)) : ($nr) ) );
            }
        }
        Rope append_helper(Rope r, __CoreCpp::CCharBuffer v) noexcept  {
            if(r.typeinfo == &Leaf𝐓𝐲𝐩𝐞) {
                [[maybe_unused]] Leaf $r = r.template access<Leaf>();
                if( ((CCharBufferᘏsize($r.buf) + CCharBufferᘏsize(v)) <= CCharBufferOps::getMaxSize()) ) {
                    __CoreCpp::CCharBuffer merge = CCharBufferOps::mergeCBuffers($r.buf, v);
                    return Rope( &Leaf𝐓𝐲𝐩𝐞, RopeᘏcreateLeaf(merge) );
                }
                if( (CCharBufferᘏsize($r.buf) < CCharBufferOps::getMaxSize()) ) {
                    [[maybe_unused]] __CoreCpp::CCharBuffer cb1;
                    [[maybe_unused]] __CoreCpp::CCharBuffer cb2;
                    {
                        __CoreCpp::Tuple2<2, 2> elist = CCharBufferOps::mergeCBuffers2($r.buf, v);
                        cb1 = elist.access<__CoreCpp::CCharBuffer, 0>();
                        cb2 = elist.access<__CoreCpp::CCharBuffer, 1>();
                    }

                    return balance(Color::Red, Rope( &Leaf𝐓𝐲𝐩𝐞, RopeᘏcreateLeaf(cb1) ), Rope( &Leaf𝐓𝐲𝐩𝐞, RopeᘏcreateLeaf(cb2) ));
                }
                return balance(Color::Red, Rope( &Leaf𝐓𝐲𝐩𝐞, $r ), Rope( &Leaf𝐓𝐲𝐩𝐞, RopeᘏcreateLeaf(v) ));
            }
            else if(r.typeinfo == &Node𝐓𝐲𝐩𝐞) {
                [[maybe_unused]] Node* $r = r.template access<Node*>();
                Rope nr = append_helper($r->r, v);
                return balance($r->c, $r->l, nr);
            }
            else {
                𝐚𝐛𝐨𝐫𝐭;
            }
        }
        Rope balance(Color c, Rope tleft, Rope tright) noexcept  {
            OptionᐸCRopeOpsᘏNodeᐳ doubleRedLL = balanceHelper_RR_LL(c, tleft, tright);
            if( doubleRedLL.typeinfo != &None𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Node* $doubleRedLL = doubleRedLL.template access<SomeᐸCRopeOpsᘏNodeᐳ>().value;
                return Rope( &Node𝐓𝐲𝐩𝐞, $doubleRedLL );
            }

            OptionᐸCRopeOpsᘏNodeᐳ doubleRedLR = balanceHelper_RR_LR(c, tleft, tright);
            if( doubleRedLR.typeinfo != &None𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Node* $doubleRedLR = doubleRedLR.template access<SomeᐸCRopeOpsᘏNodeᐳ>().value;
                return Rope( &Node𝐓𝐲𝐩𝐞, $doubleRedLR );
            }

            OptionᐸCRopeOpsᘏNodeᐳ doubleRedRL = balanceHelper_RR_RL(c, tleft, tright);
            if( doubleRedRL.typeinfo != &None𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Node* $doubleRedRL = doubleRedRL.template access<SomeᐸCRopeOpsᘏNodeᐳ>().value;
                return Rope( &Node𝐓𝐲𝐩𝐞, $doubleRedRL );
            }

            OptionᐸCRopeOpsᘏNodeᐳ doubleRedRR = balanceHelper_RR_RR(c, tleft, tright);
            if( doubleRedRR.typeinfo != &None𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Node* $doubleRedRR = doubleRedRR.template access<SomeᐸCRopeOpsᘏNodeᐳ>().value;
                return Rope( &Node𝐓𝐲𝐩𝐞, $doubleRedRR );
            }

            OptionᐸCRopeOpsᘏNodeᐳ negBlackL = balanceHelper_DB_L(c, tleft, tright);
            if( negBlackL.typeinfo != &None𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Node* $negBlackL = negBlackL.template access<SomeᐸCRopeOpsᘏNodeᐳ>().value;
                return Rope( &Node𝐓𝐲𝐩𝐞, $negBlackL );
            }

            OptionᐸCRopeOpsᘏNodeᐳ negBlackR = balanceHelper_DB_R(c, tleft, tright);
            if( negBlackR.typeinfo != &None𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Node* $negBlackR = negBlackR.template access<SomeᐸCRopeOpsᘏNodeᐳ>().value;
                return Rope( &Node𝐓𝐲𝐩𝐞, $negBlackR );
            }

            return Rope( &Node𝐓𝐲𝐩𝐞, RopeᘏcreateNode(c, tleft, tright) );
        }
        OptionᐸCRopeOpsᘏNodeᐳ balanceHelper_DB_L(Color c, Rope tleft, Rope tright) noexcept  {
            if( (c != Color::BB) ) {
                return OptionᐸCRopeOpsᘏNodeᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            if( tleft.typeinfo != &Node𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Rope $tleft = tleft;
                return OptionᐸCRopeOpsᘏNodeᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            if( (tleft.template access<Node*>()->c != Color::NB) ) {
                return OptionᐸCRopeOpsᘏNodeᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            Rope lleft = tleft.template access<Node*>()->l;
            if( lleft.typeinfo != &Node𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Rope $lleft = lleft;
                return OptionᐸCRopeOpsᘏNodeᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            Rope lright = tleft.template access<Node*>()->r;
            if( lright.typeinfo != &Node𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Rope $lright = lright;
                return OptionᐸCRopeOpsᘏNodeᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            if( ((lright.template access<Node*>()->c != Color::Black) || (lleft.template access<Node*>()->c != Color::Black)) ) {
                return OptionᐸCRopeOpsᘏNodeᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            Rope nl = balance(Color::Black, Rope( &Node𝐓𝐲𝐩𝐞, RopeᘏcreateNode(Color::Red, lleft.template access<Node*>()->l, lleft.template access<Node*>()->r) ), lright.template access<Node*>()->l);
            Node* nr = RopeᘏcreateNode(Color::Black, lright.template access<Node*>()->r, tright);
            return OptionᐸCRopeOpsᘏNodeᐳ( &SomeᐸCRopeOpsᘏNodeᐳ𝐓𝐲𝐩𝐞, SomeᐸCRopeOpsᘏNodeᐳ( RopeᘏcreateNode(Color::Black, nl, Rope( &Node𝐓𝐲𝐩𝐞, nr ))) );
        }
        OptionᐸCRopeOpsᘏNodeᐳ balanceHelper_DB_R(Color c, Rope tleft, Rope tright) noexcept  {
            if( (c != Color::BB) ) {
                return OptionᐸCRopeOpsᘏNodeᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            if( tright.typeinfo != &Node𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Rope $tright = tright;
                return OptionᐸCRopeOpsᘏNodeᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            if( (tright.template access<Node*>()->c != Color::NB) ) {
                return OptionᐸCRopeOpsᘏNodeᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            Rope rleft = tright.template access<Node*>()->l;
            if( rleft.typeinfo != &Node𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Rope $rleft = rleft;
                return OptionᐸCRopeOpsᘏNodeᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            Rope rright = tright.template access<Node*>()->r;
            if( rright.typeinfo != &Node𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Rope $rright = rright;
                return OptionᐸCRopeOpsᘏNodeᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            if( ((rright.template access<Node*>()->c != Color::Black) || (rleft.template access<Node*>()->c != Color::Black)) ) {
                return OptionᐸCRopeOpsᘏNodeᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            Node* nl = RopeᘏcreateNode(Color::Black, tleft, rleft.template access<Node*>()->l);
            Rope nr = balance(Color::Black, rleft.template access<Node*>()->r, Rope( &Node𝐓𝐲𝐩𝐞, RopeᘏcreateNode(Color::Red, rright.template access<Node*>()->l, rright.template access<Node*>()->r) ));
            return OptionᐸCRopeOpsᘏNodeᐳ( &SomeᐸCRopeOpsᘏNodeᐳ𝐓𝐲𝐩𝐞, SomeᐸCRopeOpsᘏNodeᐳ( RopeᘏcreateNode(Color::Black, Rope( &Node𝐓𝐲𝐩𝐞, nl ), nr)) );
        }
        OptionᐸCRopeOpsᘏNodeᐳ balanceHelper_RR_LL(Color c, Rope tleft, Rope tright) noexcept  {
            if( ((c != Color::Black) && (c != Color::BB)) ) {
                return OptionᐸCRopeOpsᘏNodeᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            if( tleft.typeinfo != &Node𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Rope $tleft = tleft;
                return OptionᐸCRopeOpsᘏNodeᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            Rope lleft = tleft.template access<Node*>()->l;
            if( lleft.typeinfo != &Node𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Rope $lleft = lleft;
                return OptionᐸCRopeOpsᘏNodeᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            if( ((lleft.template access<Node*>()->c != Color::Red) || (tleft.template access<Node*>()->c != Color::Red)) ) {
                return OptionᐸCRopeOpsᘏNodeᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            Node* nl = RopeᘏcreateNode(Color::Black, lleft.template access<Node*>()->l, lleft.template access<Node*>()->r);
            Node* nr = RopeᘏcreateNode(Color::Black, tleft.template access<Node*>()->r, tright);
            return OptionᐸCRopeOpsᘏNodeᐳ( &SomeᐸCRopeOpsᘏNodeᐳ𝐓𝐲𝐩𝐞, SomeᐸCRopeOpsᘏNodeᐳ( RopeᘏcreateNode(redden(c), Rope( &Node𝐓𝐲𝐩𝐞, nl ), Rope( &Node𝐓𝐲𝐩𝐞, nr ))) );
        }
        OptionᐸCRopeOpsᘏNodeᐳ balanceHelper_RR_LR(Color c, Rope tleft, Rope tright) noexcept  {
            if( ((c != Color::Black) && (c != Color::BB)) ) {
                return OptionᐸCRopeOpsᘏNodeᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            if( tleft.typeinfo != &Node𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Rope $tleft = tleft;
                return OptionᐸCRopeOpsᘏNodeᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            Rope lright = tleft.template access<Node*>()->r;
            if( lright.typeinfo != &Node𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Rope $lright = lright;
                return OptionᐸCRopeOpsᘏNodeᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            if( ((lright.template access<Node*>()->c != Color::Red) || (tleft.template access<Node*>()->c != Color::Red)) ) {
                return OptionᐸCRopeOpsᘏNodeᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            Node* nl = RopeᘏcreateNode(Color::Black, tleft.template access<Node*>()->l, lright.template access<Node*>()->l);
            Node* nr = RopeᘏcreateNode(Color::Black, lright.template access<Node*>()->r, tright);
            return OptionᐸCRopeOpsᘏNodeᐳ( &SomeᐸCRopeOpsᘏNodeᐳ𝐓𝐲𝐩𝐞, SomeᐸCRopeOpsᘏNodeᐳ( RopeᘏcreateNode(redden(c), Rope( &Node𝐓𝐲𝐩𝐞, nl ), Rope( &Node𝐓𝐲𝐩𝐞, nr ))) );
        }
        OptionᐸCRopeOpsᘏNodeᐳ balanceHelper_RR_RL(Color c, Rope tleft, Rope tright) noexcept  {
            if( ((c != Color::Black) && (c != Color::BB)) ) {
                return OptionᐸCRopeOpsᘏNodeᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            if( tright.typeinfo != &Node𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Rope $tright = tright;
                return OptionᐸCRopeOpsᘏNodeᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            Rope rleft = tright.template access<Node*>()->l;
            if( rleft.typeinfo != &Node𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Rope $rleft = rleft;
                return OptionᐸCRopeOpsᘏNodeᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            if( ((rleft.template access<Node*>()->c != Color::Red) || (tright.template access<Node*>()->c != Color::Red)) ) {
                return OptionᐸCRopeOpsᘏNodeᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            Node* nl = RopeᘏcreateNode(Color::Black, tleft, rleft.template access<Node*>()->l);
            Node* nr = RopeᘏcreateNode(Color::Black, rleft.template access<Node*>()->r, tright.template access<Node*>()->r);
            return OptionᐸCRopeOpsᘏNodeᐳ( &SomeᐸCRopeOpsᘏNodeᐳ𝐓𝐲𝐩𝐞, SomeᐸCRopeOpsᘏNodeᐳ( RopeᘏcreateNode(redden(c), Rope( &Node𝐓𝐲𝐩𝐞, nl ), Rope( &Node𝐓𝐲𝐩𝐞, nr ))) );
        }
        OptionᐸCRopeOpsᘏNodeᐳ balanceHelper_RR_RR(Color c, Rope tleft, Rope tright) noexcept  {
            if( ((c != Color::Black) && (c != Color::BB)) ) {
                return OptionᐸCRopeOpsᘏNodeᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            if( tright.typeinfo != &Node𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Rope $tright = tright;
                return OptionᐸCRopeOpsᘏNodeᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            Rope rright = tright.template access<Node*>()->r;
            if( rright.typeinfo != &Node𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Rope $rright = rright;
                return OptionᐸCRopeOpsᘏNodeᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            if( ((rright.template access<Node*>()->c != Color::Red) || (tright.template access<Node*>()->c != Color::Red)) ) {
                return OptionᐸCRopeOpsᘏNodeᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            Node* nl = RopeᘏcreateNode(Color::Black, tleft, tright.template access<Node*>()->l);
            Node* nr = RopeᘏcreateNode(Color::Black, rright.template access<Node*>()->l, rright.template access<Node*>()->r);
            return OptionᐸCRopeOpsᘏNodeᐳ( &SomeᐸCRopeOpsᘏNodeᐳ𝐓𝐲𝐩𝐞, SomeᐸCRopeOpsᘏNodeᐳ( RopeᘏcreateNode(redden(c), Rope( &Node𝐓𝐲𝐩𝐞, nl ), Rope( &Node𝐓𝐲𝐩𝐞, nr ))) );
        }
        __CoreCpp::Bool equal(Rope r1, Rope r2) noexcept  {
            if( (length(r1) != length(r2)) ) {
                return false;
            }
            CRopeIterator r1_it = CRopeIteratorᘏinitialize(r1);
            CRopeIterator r2_it = CRopeIteratorᘏinitialize(r2);
            [[maybe_unused]] __CoreCpp::CCharBuffer r1_last;
            [[maybe_unused]] __CoreCpp::CCharBuffer r2_last;
            {
                __CoreCpp::Tuple2<2, 2> elist = Algorithm::whileᐸ丨CCharBufferᐧCCharBuffer丨ᐳ(__CoreCpp::Tuple2<2, 2>(CRopeIteratorᘏnext(r1_it), CRopeIteratorᘏnext(r2_it)), [&](__CoreCpp::Tuple2<2, 2> bufs) -> __CoreCpp::Bool{ return (CRopeIteratorᘏhasNext(r1_it) && (CRopeIteratorᘏhasNext(r2_it) && CCharBufferOps::equal(bufs.access<__CoreCpp::CCharBuffer, 0>(), bufs.access<__CoreCpp::CCharBuffer, 1>()))); }, [&](__CoreCpp::Tuple2<2, 2> acc) -> __CoreCpp::Tuple2<2, 2>{ return __CoreCpp::Tuple2<2, 2>(CRopeIteratorᘏnext(r1_it), CRopeIteratorᘏnext(r2_it)); });
                r1_last = elist.access<__CoreCpp::CCharBuffer, 0>();
                r2_last = elist.access<__CoreCpp::CCharBuffer, 1>();
            }

            return CCharBufferOps::equal(r1_last, r2_last);
        }
        __CoreCpp::Nat length(Rope r) noexcept  {
            return RopeᘏgetCharacterCount(r);
        }
        __CoreCpp::Bool less(Rope r1, Rope r2) noexcept  {
            CRopeIterator r1_it = CRopeIteratorᘏinitialize(r1);
            CRopeIterator r2_it = CRopeIteratorᘏinitialize(r2);
            [[maybe_unused]] __CoreCpp::CCharBuffer r1_last;
            [[maybe_unused]] __CoreCpp::CCharBuffer r2_last;
            {
                __CoreCpp::Tuple2<2, 2> elist = Algorithm::whileᐸ丨CCharBufferᐧCCharBuffer丨ᐳ(__CoreCpp::Tuple2<2, 2>(CRopeIteratorᘏnext(r1_it), CRopeIteratorᘏnext(r2_it)), [&](__CoreCpp::Tuple2<2, 2> bufs) -> __CoreCpp::Bool{ return (CRopeIteratorᘏhasNext(r1_it) && (CRopeIteratorᘏhasNext(r2_it) && CCharBufferOps::equal(bufs.access<__CoreCpp::CCharBuffer, 0>(), bufs.access<__CoreCpp::CCharBuffer, 1>()))); }, [&](__CoreCpp::Tuple2<2, 2> acc) -> __CoreCpp::Tuple2<2, 2>{ return __CoreCpp::Tuple2<2, 2>(CRopeIteratorᘏnext(r1_it), CRopeIteratorᘏnext(r2_it)); });
                r1_last = elist.access<__CoreCpp::CCharBuffer, 0>();
                r2_last = elist.access<__CoreCpp::CCharBuffer, 1>();
            }

            return CCharBufferOps::less(r1_last, r2_last);
        }
        Color redden(Color c) noexcept  {
            𝐚𝐬𝐬𝐞𝐫𝐭((c != Color::NB));
            if( c == Color::BB ) {
                return Color::Black;
            }
            else if( c == Color::Black ) {
                return Color::Red;
            }
            else if( true ) {
                return Color::NB;
            }
            else {
                𝐚𝐛𝐨𝐫𝐭;
            }
        }
        CRope s_crope_append(CRope r, __CoreCpp::CCharBuffer buf) noexcept  {
            return append(r, buf);
        }
        CRope s_crope_create(__CoreCpp::CCharBuffer buf) noexcept  {
            return Rope( &Leaf𝐓𝐲𝐩𝐞, RopeᘏcreateLeaf(buf) );
        }
        __CoreCpp::Bool s_crope_equal(CRope cr1, CRope cr2) noexcept  {
            return equal(cr1, cr2);
        }
        __CoreCpp::Bool s_crope_less(CRope cr1, CRope cr2) noexcept  {
            return less(cr1, cr2);
        }
        Leaf RopeᘏcreateLeaf(__CoreCpp::CCharBuffer buf) noexcept  {
            return Leaf( buf );
        }
        Node* RopeᘏcreateNode(Color c, Rope l, Rope r) noexcept  {
            return 𝐀𝐥𝐥𝐨𝐜𝐓𝐲𝐩𝐞( Node, alloc8, &Node𝐓𝐲𝐩𝐞, (Node( c, RopeᘏgetCharacterCount(l), l, r )) );
        }
        __CoreCpp::Nat RopeᘏgetCharacterCount(Rope rope) noexcept  {
            if(rope.typeinfo == &Leaf𝐓𝐲𝐩𝐞) {
                [[maybe_unused]] Leaf $rope = rope.template access<Leaf>();
                return CCharBufferᘏsize($rope.buf);
            }
            else if(rope.typeinfo == &Node𝐓𝐲𝐩𝐞) {
                [[maybe_unused]] Node* $rope = rope.template access<Node*>();
                return (RopeᘏgetCharacterCount($rope->l) + RopeᘏgetCharacterCount($rope->r));
            }
            else {
                𝐚𝐛𝐨𝐫𝐭;
            }
        }
    }
    namespace ListOps {
//
// Constants
//
        inline Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳᘏemptyTree();
        inline Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᘏemptyTree();
        inline Treeᐸ丨NatᐧNat丨ᐳ Treeᐸ丨NatᐧNat丨ᐳᘏemptyTree();
        inline TreeᐸFloatᐳ TreeᐸFloatᐳᘏemptyTree();
        inline TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ TreeᐸListᐸ丨NatᐧNat丨ᐳᐳᘏemptyTree();
        inline TreeᐸMainᘏBodyᐳ TreeᐸMainᘏBodyᐳᘏemptyTree();
//
// Constants
//
        inline Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳᘏemptyTree() { return Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ( &BBLeafᐸ丨FloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞 ); }
        inline Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᘏemptyTree() { return Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ( &BBLeafᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞 ); }
        inline Treeᐸ丨NatᐧNat丨ᐳ Treeᐸ丨NatᐧNat丨ᐳᘏemptyTree() { return Treeᐸ丨NatᐧNat丨ᐳ( &BBLeafᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞 ); }
        inline TreeᐸFloatᐳ TreeᐸFloatᐳᘏemptyTree() { return TreeᐸFloatᐳ( &BBLeafᐸFloatᐳ𝐓𝐲𝐩𝐞 ); }
        inline TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ TreeᐸListᐸ丨NatᐧNat丨ᐳᐳᘏemptyTree() { return TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ( &BBLeafᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞 ); }
        inline TreeᐸMainᘏBodyᐳ TreeᐸMainᘏBodyᐳᘏemptyTree() { return TreeᐸMainᘏBodyᐳ( &BBLeafᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞 ); }
        Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ balanceᐸ丨FloatᐧFloatᐧFloat丨ᐳ(Color c, Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ tleft, Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ tright) noexcept  {
            OptionᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ doubleRedLL = balanceHelper_RR_LLᐸ丨FloatᐧFloatᐧFloat丨ᐳ(c, tleft, tright);
            if( doubleRedLL.typeinfo != &None𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ* $doubleRedLL = doubleRedLL.template access<SomeᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ>().value;
                return Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ( &Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞, $doubleRedLL );
            }

            OptionᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ doubleRedLR = balanceHelper_RR_LRᐸ丨FloatᐧFloatᐧFloat丨ᐳ(c, tleft, tright);
            if( doubleRedLR.typeinfo != &None𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ* $doubleRedLR = doubleRedLR.template access<SomeᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ>().value;
                return Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ( &Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞, $doubleRedLR );
            }

            OptionᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ doubleRedRL = balanceHelper_RR_RLᐸ丨FloatᐧFloatᐧFloat丨ᐳ(c, tleft, tright);
            if( doubleRedRL.typeinfo != &None𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ* $doubleRedRL = doubleRedRL.template access<SomeᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ>().value;
                return Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ( &Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞, $doubleRedRL );
            }

            OptionᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ doubleRedRR = balanceHelper_RR_RRᐸ丨FloatᐧFloatᐧFloat丨ᐳ(c, tleft, tright);
            if( doubleRedRR.typeinfo != &None𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ* $doubleRedRR = doubleRedRR.template access<SomeᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ>().value;
                return Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ( &Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞, $doubleRedRR );
            }

            OptionᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ negBlackL = balanceHelper_DB_Lᐸ丨FloatᐧFloatᐧFloat丨ᐳ(c, tleft, tright);
            if( negBlackL.typeinfo != &None𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ* $negBlackL = negBlackL.template access<SomeᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ>().value;
                return Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ( &Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞, $negBlackL );
            }

            OptionᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ negBlackR = balanceHelper_DB_Rᐸ丨FloatᐧFloatᐧFloat丨ᐳ(c, tleft, tright);
            if( negBlackR.typeinfo != &None𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ* $negBlackR = negBlackR.template access<SomeᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ>().value;
                return Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ( &Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞, $negBlackR );
            }

            return Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ( &Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞, Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳᘏcreateNode(c, tleft, tright) );
        }
        Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ balanceᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ(Color c, Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ tleft, Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ tright) noexcept  {
            OptionᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ doubleRedLL = balanceHelper_RR_LLᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ(c, tleft, tright);
            if( doubleRedLL.typeinfo != &None𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ* $doubleRedLL = doubleRedLL.template access<SomeᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ>().value;
                return Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ( &Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞, $doubleRedLL );
            }

            OptionᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ doubleRedLR = balanceHelper_RR_LRᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ(c, tleft, tright);
            if( doubleRedLR.typeinfo != &None𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ* $doubleRedLR = doubleRedLR.template access<SomeᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ>().value;
                return Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ( &Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞, $doubleRedLR );
            }

            OptionᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ doubleRedRL = balanceHelper_RR_RLᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ(c, tleft, tright);
            if( doubleRedRL.typeinfo != &None𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ* $doubleRedRL = doubleRedRL.template access<SomeᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ>().value;
                return Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ( &Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞, $doubleRedRL );
            }

            OptionᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ doubleRedRR = balanceHelper_RR_RRᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ(c, tleft, tright);
            if( doubleRedRR.typeinfo != &None𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ* $doubleRedRR = doubleRedRR.template access<SomeᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ>().value;
                return Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ( &Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞, $doubleRedRR );
            }

            OptionᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ negBlackL = balanceHelper_DB_Lᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ(c, tleft, tright);
            if( negBlackL.typeinfo != &None𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ* $negBlackL = negBlackL.template access<SomeᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ>().value;
                return Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ( &Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞, $negBlackL );
            }

            OptionᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ negBlackR = balanceHelper_DB_Rᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ(c, tleft, tright);
            if( negBlackR.typeinfo != &None𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ* $negBlackR = negBlackR.template access<SomeᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ>().value;
                return Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ( &Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞, $negBlackR );
            }

            return Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ( &Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞, Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᘏcreateNode(c, tleft, tright) );
        }
        Treeᐸ丨NatᐧNat丨ᐳ balanceᐸ丨NatᐧNat丨ᐳ(Color c, Treeᐸ丨NatᐧNat丨ᐳ tleft, Treeᐸ丨NatᐧNat丨ᐳ tright) noexcept  {
            OptionᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ doubleRedLL = balanceHelper_RR_LLᐸ丨NatᐧNat丨ᐳ(c, tleft, tright);
            if( doubleRedLL.typeinfo != &None𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Nodeᐸ丨NatᐧNat丨ᐳ* $doubleRedLL = doubleRedLL.template access<SomeᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ>().value;
                return Treeᐸ丨NatᐧNat丨ᐳ( &Nodeᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞, $doubleRedLL );
            }

            OptionᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ doubleRedLR = balanceHelper_RR_LRᐸ丨NatᐧNat丨ᐳ(c, tleft, tright);
            if( doubleRedLR.typeinfo != &None𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Nodeᐸ丨NatᐧNat丨ᐳ* $doubleRedLR = doubleRedLR.template access<SomeᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ>().value;
                return Treeᐸ丨NatᐧNat丨ᐳ( &Nodeᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞, $doubleRedLR );
            }

            OptionᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ doubleRedRL = balanceHelper_RR_RLᐸ丨NatᐧNat丨ᐳ(c, tleft, tright);
            if( doubleRedRL.typeinfo != &None𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Nodeᐸ丨NatᐧNat丨ᐳ* $doubleRedRL = doubleRedRL.template access<SomeᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ>().value;
                return Treeᐸ丨NatᐧNat丨ᐳ( &Nodeᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞, $doubleRedRL );
            }

            OptionᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ doubleRedRR = balanceHelper_RR_RRᐸ丨NatᐧNat丨ᐳ(c, tleft, tright);
            if( doubleRedRR.typeinfo != &None𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Nodeᐸ丨NatᐧNat丨ᐳ* $doubleRedRR = doubleRedRR.template access<SomeᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ>().value;
                return Treeᐸ丨NatᐧNat丨ᐳ( &Nodeᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞, $doubleRedRR );
            }

            OptionᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ negBlackL = balanceHelper_DB_Lᐸ丨NatᐧNat丨ᐳ(c, tleft, tright);
            if( negBlackL.typeinfo != &None𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Nodeᐸ丨NatᐧNat丨ᐳ* $negBlackL = negBlackL.template access<SomeᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ>().value;
                return Treeᐸ丨NatᐧNat丨ᐳ( &Nodeᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞, $negBlackL );
            }

            OptionᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ negBlackR = balanceHelper_DB_Rᐸ丨NatᐧNat丨ᐳ(c, tleft, tright);
            if( negBlackR.typeinfo != &None𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Nodeᐸ丨NatᐧNat丨ᐳ* $negBlackR = negBlackR.template access<SomeᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ>().value;
                return Treeᐸ丨NatᐧNat丨ᐳ( &Nodeᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞, $negBlackR );
            }

            return Treeᐸ丨NatᐧNat丨ᐳ( &Nodeᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞, Treeᐸ丨NatᐧNat丨ᐳᘏcreateNode(c, tleft, tright) );
        }
        TreeᐸFloatᐳ balanceᐸFloatᐳ(Color c, TreeᐸFloatᐳ tleft, TreeᐸFloatᐳ tright) noexcept  {
            OptionᐸListOpsᘏNodeᐸFloatᐳᐳ doubleRedLL = balanceHelper_RR_LLᐸFloatᐳ(c, tleft, tright);
            if( doubleRedLL.typeinfo != &None𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] NodeᐸFloatᐳ* $doubleRedLL = doubleRedLL.template access<SomeᐸListOpsᘏNodeᐸFloatᐳᐳ>().value;
                return TreeᐸFloatᐳ( &NodeᐸFloatᐳ𝐓𝐲𝐩𝐞, $doubleRedLL );
            }

            OptionᐸListOpsᘏNodeᐸFloatᐳᐳ doubleRedLR = balanceHelper_RR_LRᐸFloatᐳ(c, tleft, tright);
            if( doubleRedLR.typeinfo != &None𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] NodeᐸFloatᐳ* $doubleRedLR = doubleRedLR.template access<SomeᐸListOpsᘏNodeᐸFloatᐳᐳ>().value;
                return TreeᐸFloatᐳ( &NodeᐸFloatᐳ𝐓𝐲𝐩𝐞, $doubleRedLR );
            }

            OptionᐸListOpsᘏNodeᐸFloatᐳᐳ doubleRedRL = balanceHelper_RR_RLᐸFloatᐳ(c, tleft, tright);
            if( doubleRedRL.typeinfo != &None𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] NodeᐸFloatᐳ* $doubleRedRL = doubleRedRL.template access<SomeᐸListOpsᘏNodeᐸFloatᐳᐳ>().value;
                return TreeᐸFloatᐳ( &NodeᐸFloatᐳ𝐓𝐲𝐩𝐞, $doubleRedRL );
            }

            OptionᐸListOpsᘏNodeᐸFloatᐳᐳ doubleRedRR = balanceHelper_RR_RRᐸFloatᐳ(c, tleft, tright);
            if( doubleRedRR.typeinfo != &None𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] NodeᐸFloatᐳ* $doubleRedRR = doubleRedRR.template access<SomeᐸListOpsᘏNodeᐸFloatᐳᐳ>().value;
                return TreeᐸFloatᐳ( &NodeᐸFloatᐳ𝐓𝐲𝐩𝐞, $doubleRedRR );
            }

            OptionᐸListOpsᘏNodeᐸFloatᐳᐳ negBlackL = balanceHelper_DB_LᐸFloatᐳ(c, tleft, tright);
            if( negBlackL.typeinfo != &None𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] NodeᐸFloatᐳ* $negBlackL = negBlackL.template access<SomeᐸListOpsᘏNodeᐸFloatᐳᐳ>().value;
                return TreeᐸFloatᐳ( &NodeᐸFloatᐳ𝐓𝐲𝐩𝐞, $negBlackL );
            }

            OptionᐸListOpsᘏNodeᐸFloatᐳᐳ negBlackR = balanceHelper_DB_RᐸFloatᐳ(c, tleft, tright);
            if( negBlackR.typeinfo != &None𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] NodeᐸFloatᐳ* $negBlackR = negBlackR.template access<SomeᐸListOpsᘏNodeᐸFloatᐳᐳ>().value;
                return TreeᐸFloatᐳ( &NodeᐸFloatᐳ𝐓𝐲𝐩𝐞, $negBlackR );
            }

            return TreeᐸFloatᐳ( &NodeᐸFloatᐳ𝐓𝐲𝐩𝐞, TreeᐸFloatᐳᘏcreateNode(c, tleft, tright) );
        }
        TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ balanceᐸListᐸ丨NatᐧNat丨ᐳᐳ(Color c, TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ tleft, TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ tright) noexcept  {
            OptionᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ doubleRedLL = balanceHelper_RR_LLᐸListᐸ丨NatᐧNat丨ᐳᐳ(c, tleft, tright);
            if( doubleRedLL.typeinfo != &None𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ* $doubleRedLL = doubleRedLL.template access<SomeᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ>().value;
                return TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ( &NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞, $doubleRedLL );
            }

            OptionᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ doubleRedLR = balanceHelper_RR_LRᐸListᐸ丨NatᐧNat丨ᐳᐳ(c, tleft, tright);
            if( doubleRedLR.typeinfo != &None𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ* $doubleRedLR = doubleRedLR.template access<SomeᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ>().value;
                return TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ( &NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞, $doubleRedLR );
            }

            OptionᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ doubleRedRL = balanceHelper_RR_RLᐸListᐸ丨NatᐧNat丨ᐳᐳ(c, tleft, tright);
            if( doubleRedRL.typeinfo != &None𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ* $doubleRedRL = doubleRedRL.template access<SomeᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ>().value;
                return TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ( &NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞, $doubleRedRL );
            }

            OptionᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ doubleRedRR = balanceHelper_RR_RRᐸListᐸ丨NatᐧNat丨ᐳᐳ(c, tleft, tright);
            if( doubleRedRR.typeinfo != &None𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ* $doubleRedRR = doubleRedRR.template access<SomeᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ>().value;
                return TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ( &NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞, $doubleRedRR );
            }

            OptionᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ negBlackL = balanceHelper_DB_LᐸListᐸ丨NatᐧNat丨ᐳᐳ(c, tleft, tright);
            if( negBlackL.typeinfo != &None𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ* $negBlackL = negBlackL.template access<SomeᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ>().value;
                return TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ( &NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞, $negBlackL );
            }

            OptionᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ negBlackR = balanceHelper_DB_RᐸListᐸ丨NatᐧNat丨ᐳᐳ(c, tleft, tright);
            if( negBlackR.typeinfo != &None𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ* $negBlackR = negBlackR.template access<SomeᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ>().value;
                return TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ( &NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞, $negBlackR );
            }

            return TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ( &NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞, TreeᐸListᐸ丨NatᐧNat丨ᐳᐳᘏcreateNode(c, tleft, tright) );
        }
        TreeᐸMainᘏBodyᐳ balanceᐸMainᘏBodyᐳ(Color c, TreeᐸMainᘏBodyᐳ tleft, TreeᐸMainᘏBodyᐳ tright) noexcept  {
            OptionᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ doubleRedLL = balanceHelper_RR_LLᐸMainᘏBodyᐳ(c, tleft, tright);
            if( doubleRedLL.typeinfo != &None𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] NodeᐸMainᘏBodyᐳ* $doubleRedLL = doubleRedLL.template access<SomeᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ>().value;
                return TreeᐸMainᘏBodyᐳ( &NodeᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞, $doubleRedLL );
            }

            OptionᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ doubleRedLR = balanceHelper_RR_LRᐸMainᘏBodyᐳ(c, tleft, tright);
            if( doubleRedLR.typeinfo != &None𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] NodeᐸMainᘏBodyᐳ* $doubleRedLR = doubleRedLR.template access<SomeᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ>().value;
                return TreeᐸMainᘏBodyᐳ( &NodeᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞, $doubleRedLR );
            }

            OptionᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ doubleRedRL = balanceHelper_RR_RLᐸMainᘏBodyᐳ(c, tleft, tright);
            if( doubleRedRL.typeinfo != &None𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] NodeᐸMainᘏBodyᐳ* $doubleRedRL = doubleRedRL.template access<SomeᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ>().value;
                return TreeᐸMainᘏBodyᐳ( &NodeᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞, $doubleRedRL );
            }

            OptionᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ doubleRedRR = balanceHelper_RR_RRᐸMainᘏBodyᐳ(c, tleft, tright);
            if( doubleRedRR.typeinfo != &None𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] NodeᐸMainᘏBodyᐳ* $doubleRedRR = doubleRedRR.template access<SomeᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ>().value;
                return TreeᐸMainᘏBodyᐳ( &NodeᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞, $doubleRedRR );
            }

            OptionᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ negBlackL = balanceHelper_DB_LᐸMainᘏBodyᐳ(c, tleft, tright);
            if( negBlackL.typeinfo != &None𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] NodeᐸMainᘏBodyᐳ* $negBlackL = negBlackL.template access<SomeᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ>().value;
                return TreeᐸMainᘏBodyᐳ( &NodeᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞, $negBlackL );
            }

            OptionᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ negBlackR = balanceHelper_DB_RᐸMainᘏBodyᐳ(c, tleft, tright);
            if( negBlackR.typeinfo != &None𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] NodeᐸMainᘏBodyᐳ* $negBlackR = negBlackR.template access<SomeᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ>().value;
                return TreeᐸMainᘏBodyᐳ( &NodeᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞, $negBlackR );
            }

            return TreeᐸMainᘏBodyᐳ( &NodeᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞, TreeᐸMainᘏBodyᐳᘏcreateNode(c, tleft, tright) );
        }
        OptionᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ balanceHelper_DB_Lᐸ丨FloatᐧFloatᐧFloat丨ᐳ(Color c, Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ tleft, Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ tright) noexcept  {
            if( (c != Color::BB) ) {
                return OptionᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            if( tleft.typeinfo != &Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ $tleft = tleft;
                return OptionᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            if( (tleft.template access<Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ*>()->c != Color::NB) ) {
                return OptionᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ lleft = tleft.template access<Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ*>()->l;
            if( lleft.typeinfo != &Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ $lleft = lleft;
                return OptionᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ lright = tleft.template access<Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ*>()->r;
            if( lright.typeinfo != &Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ $lright = lright;
                return OptionᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            if( ((lright.template access<Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ*>()->c != Color::Black) || (lleft.template access<Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ*>()->c != Color::Black)) ) {
                return OptionᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ nl = balanceᐸ丨FloatᐧFloatᐧFloat丨ᐳ(Color::Black, Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ( &Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞, Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳᘏcreateNode(Color::Red, lleft.template access<Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ*>()->l, lleft.template access<Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ*>()->r) ), lright.template access<Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ*>()->l);
            Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ* nr = Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳᘏcreateNode(Color::Black, lright.template access<Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ*>()->r, tright);
            return OptionᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ( &SomeᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ𝐓𝐲𝐩𝐞, SomeᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ( Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳᘏcreateNode(Color::Black, nl, Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ( &Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞, nr ))) );
        }
        OptionᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ balanceHelper_DB_Lᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ(Color c, Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ tleft, Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ tright) noexcept  {
            if( (c != Color::BB) ) {
                return OptionᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            if( tleft.typeinfo != &Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ $tleft = tleft;
                return OptionᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            if( (tleft.template access<Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ*>()->c != Color::NB) ) {
                return OptionᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ lleft = tleft.template access<Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ*>()->l;
            if( lleft.typeinfo != &Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ $lleft = lleft;
                return OptionᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ lright = tleft.template access<Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ*>()->r;
            if( lright.typeinfo != &Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ $lright = lright;
                return OptionᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            if( ((lright.template access<Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ*>()->c != Color::Black) || (lleft.template access<Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ*>()->c != Color::Black)) ) {
                return OptionᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ nl = balanceᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ(Color::Black, Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ( &Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞, Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᘏcreateNode(Color::Red, lleft.template access<Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ*>()->l, lleft.template access<Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ*>()->r) ), lright.template access<Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ*>()->l);
            Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ* nr = Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᘏcreateNode(Color::Black, lright.template access<Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ*>()->r, tright);
            return OptionᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ( &SomeᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ𝐓𝐲𝐩𝐞, SomeᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ( Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᘏcreateNode(Color::Black, nl, Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ( &Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞, nr ))) );
        }
        OptionᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ balanceHelper_DB_Lᐸ丨NatᐧNat丨ᐳ(Color c, Treeᐸ丨NatᐧNat丨ᐳ tleft, Treeᐸ丨NatᐧNat丨ᐳ tright) noexcept  {
            if( (c != Color::BB) ) {
                return OptionᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            if( tleft.typeinfo != &Nodeᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Treeᐸ丨NatᐧNat丨ᐳ $tleft = tleft;
                return OptionᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            if( (tleft.template access<Nodeᐸ丨NatᐧNat丨ᐳ*>()->c != Color::NB) ) {
                return OptionᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            Treeᐸ丨NatᐧNat丨ᐳ lleft = tleft.template access<Nodeᐸ丨NatᐧNat丨ᐳ*>()->l;
            if( lleft.typeinfo != &Nodeᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Treeᐸ丨NatᐧNat丨ᐳ $lleft = lleft;
                return OptionᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            Treeᐸ丨NatᐧNat丨ᐳ lright = tleft.template access<Nodeᐸ丨NatᐧNat丨ᐳ*>()->r;
            if( lright.typeinfo != &Nodeᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Treeᐸ丨NatᐧNat丨ᐳ $lright = lright;
                return OptionᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            if( ((lright.template access<Nodeᐸ丨NatᐧNat丨ᐳ*>()->c != Color::Black) || (lleft.template access<Nodeᐸ丨NatᐧNat丨ᐳ*>()->c != Color::Black)) ) {
                return OptionᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            Treeᐸ丨NatᐧNat丨ᐳ nl = balanceᐸ丨NatᐧNat丨ᐳ(Color::Black, Treeᐸ丨NatᐧNat丨ᐳ( &Nodeᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞, Treeᐸ丨NatᐧNat丨ᐳᘏcreateNode(Color::Red, lleft.template access<Nodeᐸ丨NatᐧNat丨ᐳ*>()->l, lleft.template access<Nodeᐸ丨NatᐧNat丨ᐳ*>()->r) ), lright.template access<Nodeᐸ丨NatᐧNat丨ᐳ*>()->l);
            Nodeᐸ丨NatᐧNat丨ᐳ* nr = Treeᐸ丨NatᐧNat丨ᐳᘏcreateNode(Color::Black, lright.template access<Nodeᐸ丨NatᐧNat丨ᐳ*>()->r, tright);
            return OptionᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ( &SomeᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞, SomeᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ( Treeᐸ丨NatᐧNat丨ᐳᘏcreateNode(Color::Black, nl, Treeᐸ丨NatᐧNat丨ᐳ( &Nodeᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞, nr ))) );
        }
        OptionᐸListOpsᘏNodeᐸFloatᐳᐳ balanceHelper_DB_LᐸFloatᐳ(Color c, TreeᐸFloatᐳ tleft, TreeᐸFloatᐳ tright) noexcept  {
            if( (c != Color::BB) ) {
                return OptionᐸListOpsᘏNodeᐸFloatᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            if( tleft.typeinfo != &NodeᐸFloatᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] TreeᐸFloatᐳ $tleft = tleft;
                return OptionᐸListOpsᘏNodeᐸFloatᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            if( (tleft.template access<NodeᐸFloatᐳ*>()->c != Color::NB) ) {
                return OptionᐸListOpsᘏNodeᐸFloatᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            TreeᐸFloatᐳ lleft = tleft.template access<NodeᐸFloatᐳ*>()->l;
            if( lleft.typeinfo != &NodeᐸFloatᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] TreeᐸFloatᐳ $lleft = lleft;
                return OptionᐸListOpsᘏNodeᐸFloatᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            TreeᐸFloatᐳ lright = tleft.template access<NodeᐸFloatᐳ*>()->r;
            if( lright.typeinfo != &NodeᐸFloatᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] TreeᐸFloatᐳ $lright = lright;
                return OptionᐸListOpsᘏNodeᐸFloatᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            if( ((lright.template access<NodeᐸFloatᐳ*>()->c != Color::Black) || (lleft.template access<NodeᐸFloatᐳ*>()->c != Color::Black)) ) {
                return OptionᐸListOpsᘏNodeᐸFloatᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            TreeᐸFloatᐳ nl = balanceᐸFloatᐳ(Color::Black, TreeᐸFloatᐳ( &NodeᐸFloatᐳ𝐓𝐲𝐩𝐞, TreeᐸFloatᐳᘏcreateNode(Color::Red, lleft.template access<NodeᐸFloatᐳ*>()->l, lleft.template access<NodeᐸFloatᐳ*>()->r) ), lright.template access<NodeᐸFloatᐳ*>()->l);
            NodeᐸFloatᐳ* nr = TreeᐸFloatᐳᘏcreateNode(Color::Black, lright.template access<NodeᐸFloatᐳ*>()->r, tright);
            return OptionᐸListOpsᘏNodeᐸFloatᐳᐳ( &SomeᐸListOpsᘏNodeᐸFloatᐳᐳ𝐓𝐲𝐩𝐞, SomeᐸListOpsᘏNodeᐸFloatᐳᐳ( TreeᐸFloatᐳᘏcreateNode(Color::Black, nl, TreeᐸFloatᐳ( &NodeᐸFloatᐳ𝐓𝐲𝐩𝐞, nr ))) );
        }
        OptionᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ balanceHelper_DB_LᐸListᐸ丨NatᐧNat丨ᐳᐳ(Color c, TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ tleft, TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ tright) noexcept  {
            if( (c != Color::BB) ) {
                return OptionᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            if( tleft.typeinfo != &NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ $tleft = tleft;
                return OptionᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            if( (tleft.template access<NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ*>()->c != Color::NB) ) {
                return OptionᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ lleft = tleft.template access<NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ*>()->l;
            if( lleft.typeinfo != &NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ $lleft = lleft;
                return OptionᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ lright = tleft.template access<NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ*>()->r;
            if( lright.typeinfo != &NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ $lright = lright;
                return OptionᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            if( ((lright.template access<NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ*>()->c != Color::Black) || (lleft.template access<NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ*>()->c != Color::Black)) ) {
                return OptionᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ nl = balanceᐸListᐸ丨NatᐧNat丨ᐳᐳ(Color::Black, TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ( &NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞, TreeᐸListᐸ丨NatᐧNat丨ᐳᐳᘏcreateNode(Color::Red, lleft.template access<NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ*>()->l, lleft.template access<NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ*>()->r) ), lright.template access<NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ*>()->l);
            NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ* nr = TreeᐸListᐸ丨NatᐧNat丨ᐳᐳᘏcreateNode(Color::Black, lright.template access<NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ*>()->r, tright);
            return OptionᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ( &SomeᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ𝐓𝐲𝐩𝐞, SomeᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ( TreeᐸListᐸ丨NatᐧNat丨ᐳᐳᘏcreateNode(Color::Black, nl, TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ( &NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞, nr ))) );
        }
        OptionᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ balanceHelper_DB_LᐸMainᘏBodyᐳ(Color c, TreeᐸMainᘏBodyᐳ tleft, TreeᐸMainᘏBodyᐳ tright) noexcept  {
            if( (c != Color::BB) ) {
                return OptionᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            if( tleft.typeinfo != &NodeᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] TreeᐸMainᘏBodyᐳ $tleft = tleft;
                return OptionᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            if( (tleft.template access<NodeᐸMainᘏBodyᐳ*>()->c != Color::NB) ) {
                return OptionᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            TreeᐸMainᘏBodyᐳ lleft = tleft.template access<NodeᐸMainᘏBodyᐳ*>()->l;
            if( lleft.typeinfo != &NodeᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] TreeᐸMainᘏBodyᐳ $lleft = lleft;
                return OptionᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            TreeᐸMainᘏBodyᐳ lright = tleft.template access<NodeᐸMainᘏBodyᐳ*>()->r;
            if( lright.typeinfo != &NodeᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] TreeᐸMainᘏBodyᐳ $lright = lright;
                return OptionᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            if( ((lright.template access<NodeᐸMainᘏBodyᐳ*>()->c != Color::Black) || (lleft.template access<NodeᐸMainᘏBodyᐳ*>()->c != Color::Black)) ) {
                return OptionᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            TreeᐸMainᘏBodyᐳ nl = balanceᐸMainᘏBodyᐳ(Color::Black, TreeᐸMainᘏBodyᐳ( &NodeᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞, TreeᐸMainᘏBodyᐳᘏcreateNode(Color::Red, lleft.template access<NodeᐸMainᘏBodyᐳ*>()->l, lleft.template access<NodeᐸMainᘏBodyᐳ*>()->r) ), lright.template access<NodeᐸMainᘏBodyᐳ*>()->l);
            NodeᐸMainᘏBodyᐳ* nr = TreeᐸMainᘏBodyᐳᘏcreateNode(Color::Black, lright.template access<NodeᐸMainᘏBodyᐳ*>()->r, tright);
            return OptionᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ( &SomeᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ𝐓𝐲𝐩𝐞, SomeᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ( TreeᐸMainᘏBodyᐳᘏcreateNode(Color::Black, nl, TreeᐸMainᘏBodyᐳ( &NodeᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞, nr ))) );
        }
        OptionᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ balanceHelper_DB_Rᐸ丨FloatᐧFloatᐧFloat丨ᐳ(Color c, Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ tleft, Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ tright) noexcept  {
            if( (c != Color::BB) ) {
                return OptionᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            if( tright.typeinfo != &Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ $tright = tright;
                return OptionᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            if( (tright.template access<Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ*>()->c != Color::NB) ) {
                return OptionᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ rleft = tright.template access<Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ*>()->l;
            if( rleft.typeinfo != &Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ $rleft = rleft;
                return OptionᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ rright = tright.template access<Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ*>()->r;
            if( rright.typeinfo != &Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ $rright = rright;
                return OptionᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            if( ((rright.template access<Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ*>()->c != Color::Black) || (rleft.template access<Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ*>()->c != Color::Black)) ) {
                return OptionᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ* nl = Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳᘏcreateNode(Color::Black, tleft, rleft.template access<Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ*>()->l);
            Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ nr = balanceᐸ丨FloatᐧFloatᐧFloat丨ᐳ(Color::Black, rleft.template access<Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ*>()->r, Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ( &Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞, Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳᘏcreateNode(Color::Red, rright.template access<Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ*>()->l, rright.template access<Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ*>()->r) ));
            return OptionᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ( &SomeᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ𝐓𝐲𝐩𝐞, SomeᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ( Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳᘏcreateNode(Color::Black, Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ( &Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞, nl ), nr)) );
        }
        OptionᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ balanceHelper_DB_Rᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ(Color c, Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ tleft, Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ tright) noexcept  {
            if( (c != Color::BB) ) {
                return OptionᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            if( tright.typeinfo != &Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ $tright = tright;
                return OptionᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            if( (tright.template access<Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ*>()->c != Color::NB) ) {
                return OptionᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ rleft = tright.template access<Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ*>()->l;
            if( rleft.typeinfo != &Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ $rleft = rleft;
                return OptionᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ rright = tright.template access<Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ*>()->r;
            if( rright.typeinfo != &Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ $rright = rright;
                return OptionᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            if( ((rright.template access<Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ*>()->c != Color::Black) || (rleft.template access<Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ*>()->c != Color::Black)) ) {
                return OptionᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ* nl = Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᘏcreateNode(Color::Black, tleft, rleft.template access<Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ*>()->l);
            Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ nr = balanceᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ(Color::Black, rleft.template access<Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ*>()->r, Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ( &Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞, Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᘏcreateNode(Color::Red, rright.template access<Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ*>()->l, rright.template access<Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ*>()->r) ));
            return OptionᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ( &SomeᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ𝐓𝐲𝐩𝐞, SomeᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ( Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᘏcreateNode(Color::Black, Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ( &Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞, nl ), nr)) );
        }
        OptionᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ balanceHelper_DB_Rᐸ丨NatᐧNat丨ᐳ(Color c, Treeᐸ丨NatᐧNat丨ᐳ tleft, Treeᐸ丨NatᐧNat丨ᐳ tright) noexcept  {
            if( (c != Color::BB) ) {
                return OptionᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            if( tright.typeinfo != &Nodeᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Treeᐸ丨NatᐧNat丨ᐳ $tright = tright;
                return OptionᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            if( (tright.template access<Nodeᐸ丨NatᐧNat丨ᐳ*>()->c != Color::NB) ) {
                return OptionᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            Treeᐸ丨NatᐧNat丨ᐳ rleft = tright.template access<Nodeᐸ丨NatᐧNat丨ᐳ*>()->l;
            if( rleft.typeinfo != &Nodeᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Treeᐸ丨NatᐧNat丨ᐳ $rleft = rleft;
                return OptionᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            Treeᐸ丨NatᐧNat丨ᐳ rright = tright.template access<Nodeᐸ丨NatᐧNat丨ᐳ*>()->r;
            if( rright.typeinfo != &Nodeᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Treeᐸ丨NatᐧNat丨ᐳ $rright = rright;
                return OptionᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            if( ((rright.template access<Nodeᐸ丨NatᐧNat丨ᐳ*>()->c != Color::Black) || (rleft.template access<Nodeᐸ丨NatᐧNat丨ᐳ*>()->c != Color::Black)) ) {
                return OptionᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            Nodeᐸ丨NatᐧNat丨ᐳ* nl = Treeᐸ丨NatᐧNat丨ᐳᘏcreateNode(Color::Black, tleft, rleft.template access<Nodeᐸ丨NatᐧNat丨ᐳ*>()->l);
            Treeᐸ丨NatᐧNat丨ᐳ nr = balanceᐸ丨NatᐧNat丨ᐳ(Color::Black, rleft.template access<Nodeᐸ丨NatᐧNat丨ᐳ*>()->r, Treeᐸ丨NatᐧNat丨ᐳ( &Nodeᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞, Treeᐸ丨NatᐧNat丨ᐳᘏcreateNode(Color::Red, rright.template access<Nodeᐸ丨NatᐧNat丨ᐳ*>()->l, rright.template access<Nodeᐸ丨NatᐧNat丨ᐳ*>()->r) ));
            return OptionᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ( &SomeᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞, SomeᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ( Treeᐸ丨NatᐧNat丨ᐳᘏcreateNode(Color::Black, Treeᐸ丨NatᐧNat丨ᐳ( &Nodeᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞, nl ), nr)) );
        }
        OptionᐸListOpsᘏNodeᐸFloatᐳᐳ balanceHelper_DB_RᐸFloatᐳ(Color c, TreeᐸFloatᐳ tleft, TreeᐸFloatᐳ tright) noexcept  {
            if( (c != Color::BB) ) {
                return OptionᐸListOpsᘏNodeᐸFloatᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            if( tright.typeinfo != &NodeᐸFloatᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] TreeᐸFloatᐳ $tright = tright;
                return OptionᐸListOpsᘏNodeᐸFloatᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            if( (tright.template access<NodeᐸFloatᐳ*>()->c != Color::NB) ) {
                return OptionᐸListOpsᘏNodeᐸFloatᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            TreeᐸFloatᐳ rleft = tright.template access<NodeᐸFloatᐳ*>()->l;
            if( rleft.typeinfo != &NodeᐸFloatᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] TreeᐸFloatᐳ $rleft = rleft;
                return OptionᐸListOpsᘏNodeᐸFloatᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            TreeᐸFloatᐳ rright = tright.template access<NodeᐸFloatᐳ*>()->r;
            if( rright.typeinfo != &NodeᐸFloatᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] TreeᐸFloatᐳ $rright = rright;
                return OptionᐸListOpsᘏNodeᐸFloatᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            if( ((rright.template access<NodeᐸFloatᐳ*>()->c != Color::Black) || (rleft.template access<NodeᐸFloatᐳ*>()->c != Color::Black)) ) {
                return OptionᐸListOpsᘏNodeᐸFloatᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            NodeᐸFloatᐳ* nl = TreeᐸFloatᐳᘏcreateNode(Color::Black, tleft, rleft.template access<NodeᐸFloatᐳ*>()->l);
            TreeᐸFloatᐳ nr = balanceᐸFloatᐳ(Color::Black, rleft.template access<NodeᐸFloatᐳ*>()->r, TreeᐸFloatᐳ( &NodeᐸFloatᐳ𝐓𝐲𝐩𝐞, TreeᐸFloatᐳᘏcreateNode(Color::Red, rright.template access<NodeᐸFloatᐳ*>()->l, rright.template access<NodeᐸFloatᐳ*>()->r) ));
            return OptionᐸListOpsᘏNodeᐸFloatᐳᐳ( &SomeᐸListOpsᘏNodeᐸFloatᐳᐳ𝐓𝐲𝐩𝐞, SomeᐸListOpsᘏNodeᐸFloatᐳᐳ( TreeᐸFloatᐳᘏcreateNode(Color::Black, TreeᐸFloatᐳ( &NodeᐸFloatᐳ𝐓𝐲𝐩𝐞, nl ), nr)) );
        }
        OptionᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ balanceHelper_DB_RᐸListᐸ丨NatᐧNat丨ᐳᐳ(Color c, TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ tleft, TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ tright) noexcept  {
            if( (c != Color::BB) ) {
                return OptionᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            if( tright.typeinfo != &NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ $tright = tright;
                return OptionᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            if( (tright.template access<NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ*>()->c != Color::NB) ) {
                return OptionᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ rleft = tright.template access<NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ*>()->l;
            if( rleft.typeinfo != &NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ $rleft = rleft;
                return OptionᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ rright = tright.template access<NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ*>()->r;
            if( rright.typeinfo != &NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ $rright = rright;
                return OptionᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            if( ((rright.template access<NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ*>()->c != Color::Black) || (rleft.template access<NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ*>()->c != Color::Black)) ) {
                return OptionᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ* nl = TreeᐸListᐸ丨NatᐧNat丨ᐳᐳᘏcreateNode(Color::Black, tleft, rleft.template access<NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ*>()->l);
            TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ nr = balanceᐸListᐸ丨NatᐧNat丨ᐳᐳ(Color::Black, rleft.template access<NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ*>()->r, TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ( &NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞, TreeᐸListᐸ丨NatᐧNat丨ᐳᐳᘏcreateNode(Color::Red, rright.template access<NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ*>()->l, rright.template access<NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ*>()->r) ));
            return OptionᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ( &SomeᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ𝐓𝐲𝐩𝐞, SomeᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ( TreeᐸListᐸ丨NatᐧNat丨ᐳᐳᘏcreateNode(Color::Black, TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ( &NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞, nl ), nr)) );
        }
        OptionᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ balanceHelper_DB_RᐸMainᘏBodyᐳ(Color c, TreeᐸMainᘏBodyᐳ tleft, TreeᐸMainᘏBodyᐳ tright) noexcept  {
            if( (c != Color::BB) ) {
                return OptionᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            if( tright.typeinfo != &NodeᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] TreeᐸMainᘏBodyᐳ $tright = tright;
                return OptionᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            if( (tright.template access<NodeᐸMainᘏBodyᐳ*>()->c != Color::NB) ) {
                return OptionᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            TreeᐸMainᘏBodyᐳ rleft = tright.template access<NodeᐸMainᘏBodyᐳ*>()->l;
            if( rleft.typeinfo != &NodeᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] TreeᐸMainᘏBodyᐳ $rleft = rleft;
                return OptionᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            TreeᐸMainᘏBodyᐳ rright = tright.template access<NodeᐸMainᘏBodyᐳ*>()->r;
            if( rright.typeinfo != &NodeᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] TreeᐸMainᘏBodyᐳ $rright = rright;
                return OptionᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            if( ((rright.template access<NodeᐸMainᘏBodyᐳ*>()->c != Color::Black) || (rleft.template access<NodeᐸMainᘏBodyᐳ*>()->c != Color::Black)) ) {
                return OptionᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            NodeᐸMainᘏBodyᐳ* nl = TreeᐸMainᘏBodyᐳᘏcreateNode(Color::Black, tleft, rleft.template access<NodeᐸMainᘏBodyᐳ*>()->l);
            TreeᐸMainᘏBodyᐳ nr = balanceᐸMainᘏBodyᐳ(Color::Black, rleft.template access<NodeᐸMainᘏBodyᐳ*>()->r, TreeᐸMainᘏBodyᐳ( &NodeᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞, TreeᐸMainᘏBodyᐳᘏcreateNode(Color::Red, rright.template access<NodeᐸMainᘏBodyᐳ*>()->l, rright.template access<NodeᐸMainᘏBodyᐳ*>()->r) ));
            return OptionᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ( &SomeᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ𝐓𝐲𝐩𝐞, SomeᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ( TreeᐸMainᘏBodyᐳᘏcreateNode(Color::Black, TreeᐸMainᘏBodyᐳ( &NodeᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞, nl ), nr)) );
        }
        OptionᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ balanceHelper_RR_LLᐸ丨FloatᐧFloatᐧFloat丨ᐳ(Color c, Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ tleft, Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ tright) noexcept  {
            if( ((c != Color::Black) && (c != Color::BB)) ) {
                return OptionᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            if( tleft.typeinfo != &Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ $tleft = tleft;
                return OptionᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ lleft = tleft.template access<Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ*>()->l;
            if( lleft.typeinfo != &Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ $lleft = lleft;
                return OptionᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            if( ((lleft.template access<Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ*>()->c != Color::Red) || (tleft.template access<Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ*>()->c != Color::Red)) ) {
                return OptionᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ* nl = Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳᘏcreateNode(Color::Black, lleft.template access<Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ*>()->l, lleft.template access<Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ*>()->r);
            Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ* nr = Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳᘏcreateNode(Color::Black, tleft.template access<Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ*>()->r, tright);
            return OptionᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ( &SomeᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ𝐓𝐲𝐩𝐞, SomeᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ( Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳᘏcreateNode(redden(c), Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ( &Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞, nl ), Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ( &Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞, nr ))) );
        }
        OptionᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ balanceHelper_RR_LLᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ(Color c, Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ tleft, Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ tright) noexcept  {
            if( ((c != Color::Black) && (c != Color::BB)) ) {
                return OptionᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            if( tleft.typeinfo != &Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ $tleft = tleft;
                return OptionᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ lleft = tleft.template access<Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ*>()->l;
            if( lleft.typeinfo != &Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ $lleft = lleft;
                return OptionᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            if( ((lleft.template access<Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ*>()->c != Color::Red) || (tleft.template access<Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ*>()->c != Color::Red)) ) {
                return OptionᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ* nl = Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᘏcreateNode(Color::Black, lleft.template access<Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ*>()->l, lleft.template access<Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ*>()->r);
            Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ* nr = Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᘏcreateNode(Color::Black, tleft.template access<Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ*>()->r, tright);
            return OptionᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ( &SomeᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ𝐓𝐲𝐩𝐞, SomeᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ( Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᘏcreateNode(redden(c), Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ( &Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞, nl ), Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ( &Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞, nr ))) );
        }
        OptionᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ balanceHelper_RR_LLᐸ丨NatᐧNat丨ᐳ(Color c, Treeᐸ丨NatᐧNat丨ᐳ tleft, Treeᐸ丨NatᐧNat丨ᐳ tright) noexcept  {
            if( ((c != Color::Black) && (c != Color::BB)) ) {
                return OptionᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            if( tleft.typeinfo != &Nodeᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Treeᐸ丨NatᐧNat丨ᐳ $tleft = tleft;
                return OptionᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            Treeᐸ丨NatᐧNat丨ᐳ lleft = tleft.template access<Nodeᐸ丨NatᐧNat丨ᐳ*>()->l;
            if( lleft.typeinfo != &Nodeᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Treeᐸ丨NatᐧNat丨ᐳ $lleft = lleft;
                return OptionᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            if( ((lleft.template access<Nodeᐸ丨NatᐧNat丨ᐳ*>()->c != Color::Red) || (tleft.template access<Nodeᐸ丨NatᐧNat丨ᐳ*>()->c != Color::Red)) ) {
                return OptionᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            Nodeᐸ丨NatᐧNat丨ᐳ* nl = Treeᐸ丨NatᐧNat丨ᐳᘏcreateNode(Color::Black, lleft.template access<Nodeᐸ丨NatᐧNat丨ᐳ*>()->l, lleft.template access<Nodeᐸ丨NatᐧNat丨ᐳ*>()->r);
            Nodeᐸ丨NatᐧNat丨ᐳ* nr = Treeᐸ丨NatᐧNat丨ᐳᘏcreateNode(Color::Black, tleft.template access<Nodeᐸ丨NatᐧNat丨ᐳ*>()->r, tright);
            return OptionᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ( &SomeᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞, SomeᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ( Treeᐸ丨NatᐧNat丨ᐳᘏcreateNode(redden(c), Treeᐸ丨NatᐧNat丨ᐳ( &Nodeᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞, nl ), Treeᐸ丨NatᐧNat丨ᐳ( &Nodeᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞, nr ))) );
        }
        OptionᐸListOpsᘏNodeᐸFloatᐳᐳ balanceHelper_RR_LLᐸFloatᐳ(Color c, TreeᐸFloatᐳ tleft, TreeᐸFloatᐳ tright) noexcept  {
            if( ((c != Color::Black) && (c != Color::BB)) ) {
                return OptionᐸListOpsᘏNodeᐸFloatᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            if( tleft.typeinfo != &NodeᐸFloatᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] TreeᐸFloatᐳ $tleft = tleft;
                return OptionᐸListOpsᘏNodeᐸFloatᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            TreeᐸFloatᐳ lleft = tleft.template access<NodeᐸFloatᐳ*>()->l;
            if( lleft.typeinfo != &NodeᐸFloatᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] TreeᐸFloatᐳ $lleft = lleft;
                return OptionᐸListOpsᘏNodeᐸFloatᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            if( ((lleft.template access<NodeᐸFloatᐳ*>()->c != Color::Red) || (tleft.template access<NodeᐸFloatᐳ*>()->c != Color::Red)) ) {
                return OptionᐸListOpsᘏNodeᐸFloatᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            NodeᐸFloatᐳ* nl = TreeᐸFloatᐳᘏcreateNode(Color::Black, lleft.template access<NodeᐸFloatᐳ*>()->l, lleft.template access<NodeᐸFloatᐳ*>()->r);
            NodeᐸFloatᐳ* nr = TreeᐸFloatᐳᘏcreateNode(Color::Black, tleft.template access<NodeᐸFloatᐳ*>()->r, tright);
            return OptionᐸListOpsᘏNodeᐸFloatᐳᐳ( &SomeᐸListOpsᘏNodeᐸFloatᐳᐳ𝐓𝐲𝐩𝐞, SomeᐸListOpsᘏNodeᐸFloatᐳᐳ( TreeᐸFloatᐳᘏcreateNode(redden(c), TreeᐸFloatᐳ( &NodeᐸFloatᐳ𝐓𝐲𝐩𝐞, nl ), TreeᐸFloatᐳ( &NodeᐸFloatᐳ𝐓𝐲𝐩𝐞, nr ))) );
        }
        OptionᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ balanceHelper_RR_LLᐸListᐸ丨NatᐧNat丨ᐳᐳ(Color c, TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ tleft, TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ tright) noexcept  {
            if( ((c != Color::Black) && (c != Color::BB)) ) {
                return OptionᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            if( tleft.typeinfo != &NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ $tleft = tleft;
                return OptionᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ lleft = tleft.template access<NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ*>()->l;
            if( lleft.typeinfo != &NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ $lleft = lleft;
                return OptionᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            if( ((lleft.template access<NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ*>()->c != Color::Red) || (tleft.template access<NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ*>()->c != Color::Red)) ) {
                return OptionᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ* nl = TreeᐸListᐸ丨NatᐧNat丨ᐳᐳᘏcreateNode(Color::Black, lleft.template access<NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ*>()->l, lleft.template access<NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ*>()->r);
            NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ* nr = TreeᐸListᐸ丨NatᐧNat丨ᐳᐳᘏcreateNode(Color::Black, tleft.template access<NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ*>()->r, tright);
            return OptionᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ( &SomeᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ𝐓𝐲𝐩𝐞, SomeᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ( TreeᐸListᐸ丨NatᐧNat丨ᐳᐳᘏcreateNode(redden(c), TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ( &NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞, nl ), TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ( &NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞, nr ))) );
        }
        OptionᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ balanceHelper_RR_LLᐸMainᘏBodyᐳ(Color c, TreeᐸMainᘏBodyᐳ tleft, TreeᐸMainᘏBodyᐳ tright) noexcept  {
            if( ((c != Color::Black) && (c != Color::BB)) ) {
                return OptionᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            if( tleft.typeinfo != &NodeᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] TreeᐸMainᘏBodyᐳ $tleft = tleft;
                return OptionᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            TreeᐸMainᘏBodyᐳ lleft = tleft.template access<NodeᐸMainᘏBodyᐳ*>()->l;
            if( lleft.typeinfo != &NodeᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] TreeᐸMainᘏBodyᐳ $lleft = lleft;
                return OptionᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            if( ((lleft.template access<NodeᐸMainᘏBodyᐳ*>()->c != Color::Red) || (tleft.template access<NodeᐸMainᘏBodyᐳ*>()->c != Color::Red)) ) {
                return OptionᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            NodeᐸMainᘏBodyᐳ* nl = TreeᐸMainᘏBodyᐳᘏcreateNode(Color::Black, lleft.template access<NodeᐸMainᘏBodyᐳ*>()->l, lleft.template access<NodeᐸMainᘏBodyᐳ*>()->r);
            NodeᐸMainᘏBodyᐳ* nr = TreeᐸMainᘏBodyᐳᘏcreateNode(Color::Black, tleft.template access<NodeᐸMainᘏBodyᐳ*>()->r, tright);
            return OptionᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ( &SomeᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ𝐓𝐲𝐩𝐞, SomeᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ( TreeᐸMainᘏBodyᐳᘏcreateNode(redden(c), TreeᐸMainᘏBodyᐳ( &NodeᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞, nl ), TreeᐸMainᘏBodyᐳ( &NodeᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞, nr ))) );
        }
        OptionᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ balanceHelper_RR_LRᐸ丨FloatᐧFloatᐧFloat丨ᐳ(Color c, Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ tleft, Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ tright) noexcept  {
            if( ((c != Color::Black) && (c != Color::BB)) ) {
                return OptionᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            if( tleft.typeinfo != &Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ $tleft = tleft;
                return OptionᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ lright = tleft.template access<Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ*>()->r;
            if( lright.typeinfo != &Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ $lright = lright;
                return OptionᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            if( ((lright.template access<Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ*>()->c != Color::Red) || (tleft.template access<Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ*>()->c != Color::Red)) ) {
                return OptionᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ* nl = Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳᘏcreateNode(Color::Black, tleft.template access<Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ*>()->l, lright.template access<Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ*>()->l);
            Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ* nr = Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳᘏcreateNode(Color::Black, lright.template access<Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ*>()->r, tright);
            return OptionᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ( &SomeᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ𝐓𝐲𝐩𝐞, SomeᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ( Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳᘏcreateNode(redden(c), Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ( &Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞, nl ), Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ( &Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞, nr ))) );
        }
        OptionᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ balanceHelper_RR_LRᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ(Color c, Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ tleft, Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ tright) noexcept  {
            if( ((c != Color::Black) && (c != Color::BB)) ) {
                return OptionᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            if( tleft.typeinfo != &Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ $tleft = tleft;
                return OptionᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ lright = tleft.template access<Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ*>()->r;
            if( lright.typeinfo != &Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ $lright = lright;
                return OptionᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            if( ((lright.template access<Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ*>()->c != Color::Red) || (tleft.template access<Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ*>()->c != Color::Red)) ) {
                return OptionᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ* nl = Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᘏcreateNode(Color::Black, tleft.template access<Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ*>()->l, lright.template access<Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ*>()->l);
            Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ* nr = Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᘏcreateNode(Color::Black, lright.template access<Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ*>()->r, tright);
            return OptionᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ( &SomeᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ𝐓𝐲𝐩𝐞, SomeᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ( Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᘏcreateNode(redden(c), Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ( &Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞, nl ), Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ( &Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞, nr ))) );
        }
        OptionᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ balanceHelper_RR_LRᐸ丨NatᐧNat丨ᐳ(Color c, Treeᐸ丨NatᐧNat丨ᐳ tleft, Treeᐸ丨NatᐧNat丨ᐳ tright) noexcept  {
            if( ((c != Color::Black) && (c != Color::BB)) ) {
                return OptionᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            if( tleft.typeinfo != &Nodeᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Treeᐸ丨NatᐧNat丨ᐳ $tleft = tleft;
                return OptionᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            Treeᐸ丨NatᐧNat丨ᐳ lright = tleft.template access<Nodeᐸ丨NatᐧNat丨ᐳ*>()->r;
            if( lright.typeinfo != &Nodeᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Treeᐸ丨NatᐧNat丨ᐳ $lright = lright;
                return OptionᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            if( ((lright.template access<Nodeᐸ丨NatᐧNat丨ᐳ*>()->c != Color::Red) || (tleft.template access<Nodeᐸ丨NatᐧNat丨ᐳ*>()->c != Color::Red)) ) {
                return OptionᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            Nodeᐸ丨NatᐧNat丨ᐳ* nl = Treeᐸ丨NatᐧNat丨ᐳᘏcreateNode(Color::Black, tleft.template access<Nodeᐸ丨NatᐧNat丨ᐳ*>()->l, lright.template access<Nodeᐸ丨NatᐧNat丨ᐳ*>()->l);
            Nodeᐸ丨NatᐧNat丨ᐳ* nr = Treeᐸ丨NatᐧNat丨ᐳᘏcreateNode(Color::Black, lright.template access<Nodeᐸ丨NatᐧNat丨ᐳ*>()->r, tright);
            return OptionᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ( &SomeᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞, SomeᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ( Treeᐸ丨NatᐧNat丨ᐳᘏcreateNode(redden(c), Treeᐸ丨NatᐧNat丨ᐳ( &Nodeᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞, nl ), Treeᐸ丨NatᐧNat丨ᐳ( &Nodeᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞, nr ))) );
        }
        OptionᐸListOpsᘏNodeᐸFloatᐳᐳ balanceHelper_RR_LRᐸFloatᐳ(Color c, TreeᐸFloatᐳ tleft, TreeᐸFloatᐳ tright) noexcept  {
            if( ((c != Color::Black) && (c != Color::BB)) ) {
                return OptionᐸListOpsᘏNodeᐸFloatᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            if( tleft.typeinfo != &NodeᐸFloatᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] TreeᐸFloatᐳ $tleft = tleft;
                return OptionᐸListOpsᘏNodeᐸFloatᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            TreeᐸFloatᐳ lright = tleft.template access<NodeᐸFloatᐳ*>()->r;
            if( lright.typeinfo != &NodeᐸFloatᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] TreeᐸFloatᐳ $lright = lright;
                return OptionᐸListOpsᘏNodeᐸFloatᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            if( ((lright.template access<NodeᐸFloatᐳ*>()->c != Color::Red) || (tleft.template access<NodeᐸFloatᐳ*>()->c != Color::Red)) ) {
                return OptionᐸListOpsᘏNodeᐸFloatᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            NodeᐸFloatᐳ* nl = TreeᐸFloatᐳᘏcreateNode(Color::Black, tleft.template access<NodeᐸFloatᐳ*>()->l, lright.template access<NodeᐸFloatᐳ*>()->l);
            NodeᐸFloatᐳ* nr = TreeᐸFloatᐳᘏcreateNode(Color::Black, lright.template access<NodeᐸFloatᐳ*>()->r, tright);
            return OptionᐸListOpsᘏNodeᐸFloatᐳᐳ( &SomeᐸListOpsᘏNodeᐸFloatᐳᐳ𝐓𝐲𝐩𝐞, SomeᐸListOpsᘏNodeᐸFloatᐳᐳ( TreeᐸFloatᐳᘏcreateNode(redden(c), TreeᐸFloatᐳ( &NodeᐸFloatᐳ𝐓𝐲𝐩𝐞, nl ), TreeᐸFloatᐳ( &NodeᐸFloatᐳ𝐓𝐲𝐩𝐞, nr ))) );
        }
        OptionᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ balanceHelper_RR_LRᐸListᐸ丨NatᐧNat丨ᐳᐳ(Color c, TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ tleft, TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ tright) noexcept  {
            if( ((c != Color::Black) && (c != Color::BB)) ) {
                return OptionᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            if( tleft.typeinfo != &NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ $tleft = tleft;
                return OptionᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ lright = tleft.template access<NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ*>()->r;
            if( lright.typeinfo != &NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ $lright = lright;
                return OptionᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            if( ((lright.template access<NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ*>()->c != Color::Red) || (tleft.template access<NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ*>()->c != Color::Red)) ) {
                return OptionᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ* nl = TreeᐸListᐸ丨NatᐧNat丨ᐳᐳᘏcreateNode(Color::Black, tleft.template access<NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ*>()->l, lright.template access<NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ*>()->l);
            NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ* nr = TreeᐸListᐸ丨NatᐧNat丨ᐳᐳᘏcreateNode(Color::Black, lright.template access<NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ*>()->r, tright);
            return OptionᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ( &SomeᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ𝐓𝐲𝐩𝐞, SomeᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ( TreeᐸListᐸ丨NatᐧNat丨ᐳᐳᘏcreateNode(redden(c), TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ( &NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞, nl ), TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ( &NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞, nr ))) );
        }
        OptionᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ balanceHelper_RR_LRᐸMainᘏBodyᐳ(Color c, TreeᐸMainᘏBodyᐳ tleft, TreeᐸMainᘏBodyᐳ tright) noexcept  {
            if( ((c != Color::Black) && (c != Color::BB)) ) {
                return OptionᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            if( tleft.typeinfo != &NodeᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] TreeᐸMainᘏBodyᐳ $tleft = tleft;
                return OptionᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            TreeᐸMainᘏBodyᐳ lright = tleft.template access<NodeᐸMainᘏBodyᐳ*>()->r;
            if( lright.typeinfo != &NodeᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] TreeᐸMainᘏBodyᐳ $lright = lright;
                return OptionᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            if( ((lright.template access<NodeᐸMainᘏBodyᐳ*>()->c != Color::Red) || (tleft.template access<NodeᐸMainᘏBodyᐳ*>()->c != Color::Red)) ) {
                return OptionᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            NodeᐸMainᘏBodyᐳ* nl = TreeᐸMainᘏBodyᐳᘏcreateNode(Color::Black, tleft.template access<NodeᐸMainᘏBodyᐳ*>()->l, lright.template access<NodeᐸMainᘏBodyᐳ*>()->l);
            NodeᐸMainᘏBodyᐳ* nr = TreeᐸMainᘏBodyᐳᘏcreateNode(Color::Black, lright.template access<NodeᐸMainᘏBodyᐳ*>()->r, tright);
            return OptionᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ( &SomeᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ𝐓𝐲𝐩𝐞, SomeᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ( TreeᐸMainᘏBodyᐳᘏcreateNode(redden(c), TreeᐸMainᘏBodyᐳ( &NodeᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞, nl ), TreeᐸMainᘏBodyᐳ( &NodeᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞, nr ))) );
        }
        OptionᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ balanceHelper_RR_RLᐸ丨FloatᐧFloatᐧFloat丨ᐳ(Color c, Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ tleft, Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ tright) noexcept  {
            if( ((c != Color::Black) && (c != Color::BB)) ) {
                return OptionᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            if( tright.typeinfo != &Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ $tright = tright;
                return OptionᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ rleft = tright.template access<Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ*>()->l;
            if( rleft.typeinfo != &Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ $rleft = rleft;
                return OptionᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            if( ((rleft.template access<Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ*>()->c != Color::Red) || (tright.template access<Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ*>()->c != Color::Red)) ) {
                return OptionᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ* nl = Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳᘏcreateNode(Color::Black, tleft, rleft.template access<Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ*>()->l);
            Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ* nr = Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳᘏcreateNode(Color::Black, rleft.template access<Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ*>()->r, tright.template access<Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ*>()->r);
            return OptionᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ( &SomeᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ𝐓𝐲𝐩𝐞, SomeᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ( Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳᘏcreateNode(redden(c), Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ( &Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞, nl ), Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ( &Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞, nr ))) );
        }
        OptionᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ balanceHelper_RR_RLᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ(Color c, Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ tleft, Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ tright) noexcept  {
            if( ((c != Color::Black) && (c != Color::BB)) ) {
                return OptionᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            if( tright.typeinfo != &Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ $tright = tright;
                return OptionᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ rleft = tright.template access<Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ*>()->l;
            if( rleft.typeinfo != &Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ $rleft = rleft;
                return OptionᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            if( ((rleft.template access<Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ*>()->c != Color::Red) || (tright.template access<Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ*>()->c != Color::Red)) ) {
                return OptionᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ* nl = Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᘏcreateNode(Color::Black, tleft, rleft.template access<Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ*>()->l);
            Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ* nr = Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᘏcreateNode(Color::Black, rleft.template access<Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ*>()->r, tright.template access<Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ*>()->r);
            return OptionᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ( &SomeᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ𝐓𝐲𝐩𝐞, SomeᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ( Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᘏcreateNode(redden(c), Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ( &Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞, nl ), Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ( &Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞, nr ))) );
        }
        OptionᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ balanceHelper_RR_RLᐸ丨NatᐧNat丨ᐳ(Color c, Treeᐸ丨NatᐧNat丨ᐳ tleft, Treeᐸ丨NatᐧNat丨ᐳ tright) noexcept  {
            if( ((c != Color::Black) && (c != Color::BB)) ) {
                return OptionᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            if( tright.typeinfo != &Nodeᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Treeᐸ丨NatᐧNat丨ᐳ $tright = tright;
                return OptionᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            Treeᐸ丨NatᐧNat丨ᐳ rleft = tright.template access<Nodeᐸ丨NatᐧNat丨ᐳ*>()->l;
            if( rleft.typeinfo != &Nodeᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Treeᐸ丨NatᐧNat丨ᐳ $rleft = rleft;
                return OptionᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            if( ((rleft.template access<Nodeᐸ丨NatᐧNat丨ᐳ*>()->c != Color::Red) || (tright.template access<Nodeᐸ丨NatᐧNat丨ᐳ*>()->c != Color::Red)) ) {
                return OptionᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            Nodeᐸ丨NatᐧNat丨ᐳ* nl = Treeᐸ丨NatᐧNat丨ᐳᘏcreateNode(Color::Black, tleft, rleft.template access<Nodeᐸ丨NatᐧNat丨ᐳ*>()->l);
            Nodeᐸ丨NatᐧNat丨ᐳ* nr = Treeᐸ丨NatᐧNat丨ᐳᘏcreateNode(Color::Black, rleft.template access<Nodeᐸ丨NatᐧNat丨ᐳ*>()->r, tright.template access<Nodeᐸ丨NatᐧNat丨ᐳ*>()->r);
            return OptionᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ( &SomeᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞, SomeᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ( Treeᐸ丨NatᐧNat丨ᐳᘏcreateNode(redden(c), Treeᐸ丨NatᐧNat丨ᐳ( &Nodeᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞, nl ), Treeᐸ丨NatᐧNat丨ᐳ( &Nodeᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞, nr ))) );
        }
        OptionᐸListOpsᘏNodeᐸFloatᐳᐳ balanceHelper_RR_RLᐸFloatᐳ(Color c, TreeᐸFloatᐳ tleft, TreeᐸFloatᐳ tright) noexcept  {
            if( ((c != Color::Black) && (c != Color::BB)) ) {
                return OptionᐸListOpsᘏNodeᐸFloatᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            if( tright.typeinfo != &NodeᐸFloatᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] TreeᐸFloatᐳ $tright = tright;
                return OptionᐸListOpsᘏNodeᐸFloatᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            TreeᐸFloatᐳ rleft = tright.template access<NodeᐸFloatᐳ*>()->l;
            if( rleft.typeinfo != &NodeᐸFloatᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] TreeᐸFloatᐳ $rleft = rleft;
                return OptionᐸListOpsᘏNodeᐸFloatᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            if( ((rleft.template access<NodeᐸFloatᐳ*>()->c != Color::Red) || (tright.template access<NodeᐸFloatᐳ*>()->c != Color::Red)) ) {
                return OptionᐸListOpsᘏNodeᐸFloatᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            NodeᐸFloatᐳ* nl = TreeᐸFloatᐳᘏcreateNode(Color::Black, tleft, rleft.template access<NodeᐸFloatᐳ*>()->l);
            NodeᐸFloatᐳ* nr = TreeᐸFloatᐳᘏcreateNode(Color::Black, rleft.template access<NodeᐸFloatᐳ*>()->r, tright.template access<NodeᐸFloatᐳ*>()->r);
            return OptionᐸListOpsᘏNodeᐸFloatᐳᐳ( &SomeᐸListOpsᘏNodeᐸFloatᐳᐳ𝐓𝐲𝐩𝐞, SomeᐸListOpsᘏNodeᐸFloatᐳᐳ( TreeᐸFloatᐳᘏcreateNode(redden(c), TreeᐸFloatᐳ( &NodeᐸFloatᐳ𝐓𝐲𝐩𝐞, nl ), TreeᐸFloatᐳ( &NodeᐸFloatᐳ𝐓𝐲𝐩𝐞, nr ))) );
        }
        OptionᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ balanceHelper_RR_RLᐸListᐸ丨NatᐧNat丨ᐳᐳ(Color c, TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ tleft, TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ tright) noexcept  {
            if( ((c != Color::Black) && (c != Color::BB)) ) {
                return OptionᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            if( tright.typeinfo != &NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ $tright = tright;
                return OptionᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ rleft = tright.template access<NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ*>()->l;
            if( rleft.typeinfo != &NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ $rleft = rleft;
                return OptionᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            if( ((rleft.template access<NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ*>()->c != Color::Red) || (tright.template access<NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ*>()->c != Color::Red)) ) {
                return OptionᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ* nl = TreeᐸListᐸ丨NatᐧNat丨ᐳᐳᘏcreateNode(Color::Black, tleft, rleft.template access<NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ*>()->l);
            NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ* nr = TreeᐸListᐸ丨NatᐧNat丨ᐳᐳᘏcreateNode(Color::Black, rleft.template access<NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ*>()->r, tright.template access<NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ*>()->r);
            return OptionᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ( &SomeᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ𝐓𝐲𝐩𝐞, SomeᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ( TreeᐸListᐸ丨NatᐧNat丨ᐳᐳᘏcreateNode(redden(c), TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ( &NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞, nl ), TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ( &NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞, nr ))) );
        }
        OptionᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ balanceHelper_RR_RLᐸMainᘏBodyᐳ(Color c, TreeᐸMainᘏBodyᐳ tleft, TreeᐸMainᘏBodyᐳ tright) noexcept  {
            if( ((c != Color::Black) && (c != Color::BB)) ) {
                return OptionᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            if( tright.typeinfo != &NodeᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] TreeᐸMainᘏBodyᐳ $tright = tright;
                return OptionᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            TreeᐸMainᘏBodyᐳ rleft = tright.template access<NodeᐸMainᘏBodyᐳ*>()->l;
            if( rleft.typeinfo != &NodeᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] TreeᐸMainᘏBodyᐳ $rleft = rleft;
                return OptionᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            if( ((rleft.template access<NodeᐸMainᘏBodyᐳ*>()->c != Color::Red) || (tright.template access<NodeᐸMainᘏBodyᐳ*>()->c != Color::Red)) ) {
                return OptionᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            NodeᐸMainᘏBodyᐳ* nl = TreeᐸMainᘏBodyᐳᘏcreateNode(Color::Black, tleft, rleft.template access<NodeᐸMainᘏBodyᐳ*>()->l);
            NodeᐸMainᘏBodyᐳ* nr = TreeᐸMainᘏBodyᐳᘏcreateNode(Color::Black, rleft.template access<NodeᐸMainᘏBodyᐳ*>()->r, tright.template access<NodeᐸMainᘏBodyᐳ*>()->r);
            return OptionᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ( &SomeᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ𝐓𝐲𝐩𝐞, SomeᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ( TreeᐸMainᘏBodyᐳᘏcreateNode(redden(c), TreeᐸMainᘏBodyᐳ( &NodeᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞, nl ), TreeᐸMainᘏBodyᐳ( &NodeᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞, nr ))) );
        }
        OptionᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ balanceHelper_RR_RRᐸ丨FloatᐧFloatᐧFloat丨ᐳ(Color c, Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ tleft, Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ tright) noexcept  {
            if( ((c != Color::Black) && (c != Color::BB)) ) {
                return OptionᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            if( tright.typeinfo != &Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ $tright = tright;
                return OptionᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ rright = tright.template access<Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ*>()->r;
            if( rright.typeinfo != &Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ $rright = rright;
                return OptionᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            if( ((rright.template access<Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ*>()->c != Color::Red) || (tright.template access<Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ*>()->c != Color::Red)) ) {
                return OptionᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ* nl = Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳᘏcreateNode(Color::Black, tleft, tright.template access<Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ*>()->l);
            Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ* nr = Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳᘏcreateNode(Color::Black, rright.template access<Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ*>()->l, rright.template access<Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ*>()->r);
            return OptionᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ( &SomeᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ𝐓𝐲𝐩𝐞, SomeᐸListOpsᘏNodeᐸ丨FloatᐧFloatᐧFloat丨ᐳᐳ( Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳᘏcreateNode(redden(c), Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ( &Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞, nl ), Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ( &Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞, nr ))) );
        }
        OptionᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ balanceHelper_RR_RRᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ(Color c, Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ tleft, Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ tright) noexcept  {
            if( ((c != Color::Black) && (c != Color::BB)) ) {
                return OptionᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            if( tright.typeinfo != &Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ $tright = tright;
                return OptionᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ rright = tright.template access<Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ*>()->r;
            if( rright.typeinfo != &Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ $rright = rright;
                return OptionᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            if( ((rright.template access<Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ*>()->c != Color::Red) || (tright.template access<Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ*>()->c != Color::Red)) ) {
                return OptionᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ* nl = Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᘏcreateNode(Color::Black, tleft, tright.template access<Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ*>()->l);
            Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ* nr = Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᘏcreateNode(Color::Black, rright.template access<Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ*>()->l, rright.template access<Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ*>()->r);
            return OptionᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ( &SomeᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ𝐓𝐲𝐩𝐞, SomeᐸListOpsᘏNodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᐳ( Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᘏcreateNode(redden(c), Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ( &Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞, nl ), Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ( &Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞, nr ))) );
        }
        OptionᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ balanceHelper_RR_RRᐸ丨NatᐧNat丨ᐳ(Color c, Treeᐸ丨NatᐧNat丨ᐳ tleft, Treeᐸ丨NatᐧNat丨ᐳ tright) noexcept  {
            if( ((c != Color::Black) && (c != Color::BB)) ) {
                return OptionᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            if( tright.typeinfo != &Nodeᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Treeᐸ丨NatᐧNat丨ᐳ $tright = tright;
                return OptionᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            Treeᐸ丨NatᐧNat丨ᐳ rright = tright.template access<Nodeᐸ丨NatᐧNat丨ᐳ*>()->r;
            if( rright.typeinfo != &Nodeᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Treeᐸ丨NatᐧNat丨ᐳ $rright = rright;
                return OptionᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            if( ((rright.template access<Nodeᐸ丨NatᐧNat丨ᐳ*>()->c != Color::Red) || (tright.template access<Nodeᐸ丨NatᐧNat丨ᐳ*>()->c != Color::Red)) ) {
                return OptionᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            Nodeᐸ丨NatᐧNat丨ᐳ* nl = Treeᐸ丨NatᐧNat丨ᐳᘏcreateNode(Color::Black, tleft, tright.template access<Nodeᐸ丨NatᐧNat丨ᐳ*>()->l);
            Nodeᐸ丨NatᐧNat丨ᐳ* nr = Treeᐸ丨NatᐧNat丨ᐳᘏcreateNode(Color::Black, rright.template access<Nodeᐸ丨NatᐧNat丨ᐳ*>()->l, rright.template access<Nodeᐸ丨NatᐧNat丨ᐳ*>()->r);
            return OptionᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ( &SomeᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞, SomeᐸListOpsᘏNodeᐸ丨NatᐧNat丨ᐳᐳ( Treeᐸ丨NatᐧNat丨ᐳᘏcreateNode(redden(c), Treeᐸ丨NatᐧNat丨ᐳ( &Nodeᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞, nl ), Treeᐸ丨NatᐧNat丨ᐳ( &Nodeᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞, nr ))) );
        }
        OptionᐸListOpsᘏNodeᐸFloatᐳᐳ balanceHelper_RR_RRᐸFloatᐳ(Color c, TreeᐸFloatᐳ tleft, TreeᐸFloatᐳ tright) noexcept  {
            if( ((c != Color::Black) && (c != Color::BB)) ) {
                return OptionᐸListOpsᘏNodeᐸFloatᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            if( tright.typeinfo != &NodeᐸFloatᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] TreeᐸFloatᐳ $tright = tright;
                return OptionᐸListOpsᘏNodeᐸFloatᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            TreeᐸFloatᐳ rright = tright.template access<NodeᐸFloatᐳ*>()->r;
            if( rright.typeinfo != &NodeᐸFloatᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] TreeᐸFloatᐳ $rright = rright;
                return OptionᐸListOpsᘏNodeᐸFloatᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            if( ((rright.template access<NodeᐸFloatᐳ*>()->c != Color::Red) || (tright.template access<NodeᐸFloatᐳ*>()->c != Color::Red)) ) {
                return OptionᐸListOpsᘏNodeᐸFloatᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            NodeᐸFloatᐳ* nl = TreeᐸFloatᐳᘏcreateNode(Color::Black, tleft, tright.template access<NodeᐸFloatᐳ*>()->l);
            NodeᐸFloatᐳ* nr = TreeᐸFloatᐳᘏcreateNode(Color::Black, rright.template access<NodeᐸFloatᐳ*>()->l, rright.template access<NodeᐸFloatᐳ*>()->r);
            return OptionᐸListOpsᘏNodeᐸFloatᐳᐳ( &SomeᐸListOpsᘏNodeᐸFloatᐳᐳ𝐓𝐲𝐩𝐞, SomeᐸListOpsᘏNodeᐸFloatᐳᐳ( TreeᐸFloatᐳᘏcreateNode(redden(c), TreeᐸFloatᐳ( &NodeᐸFloatᐳ𝐓𝐲𝐩𝐞, nl ), TreeᐸFloatᐳ( &NodeᐸFloatᐳ𝐓𝐲𝐩𝐞, nr ))) );
        }
        OptionᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ balanceHelper_RR_RRᐸListᐸ丨NatᐧNat丨ᐳᐳ(Color c, TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ tleft, TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ tright) noexcept  {
            if( ((c != Color::Black) && (c != Color::BB)) ) {
                return OptionᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            if( tright.typeinfo != &NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ $tright = tright;
                return OptionᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ rright = tright.template access<NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ*>()->r;
            if( rright.typeinfo != &NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ $rright = rright;
                return OptionᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            if( ((rright.template access<NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ*>()->c != Color::Red) || (tright.template access<NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ*>()->c != Color::Red)) ) {
                return OptionᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ* nl = TreeᐸListᐸ丨NatᐧNat丨ᐳᐳᘏcreateNode(Color::Black, tleft, tright.template access<NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ*>()->l);
            NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ* nr = TreeᐸListᐸ丨NatᐧNat丨ᐳᐳᘏcreateNode(Color::Black, rright.template access<NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ*>()->l, rright.template access<NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ*>()->r);
            return OptionᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ( &SomeᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ𝐓𝐲𝐩𝐞, SomeᐸListOpsᘏNodeᐸListᐸ丨NatᐧNat丨ᐳᐳᐳ( TreeᐸListᐸ丨NatᐧNat丨ᐳᐳᘏcreateNode(redden(c), TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ( &NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞, nl ), TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ( &NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞, nr ))) );
        }
        OptionᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ balanceHelper_RR_RRᐸMainᘏBodyᐳ(Color c, TreeᐸMainᘏBodyᐳ tleft, TreeᐸMainᘏBodyᐳ tright) noexcept  {
            if( ((c != Color::Black) && (c != Color::BB)) ) {
                return OptionᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            if( tright.typeinfo != &NodeᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] TreeᐸMainᘏBodyᐳ $tright = tright;
                return OptionᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            TreeᐸMainᘏBodyᐳ rright = tright.template access<NodeᐸMainᘏBodyᐳ*>()->r;
            if( rright.typeinfo != &NodeᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] TreeᐸMainᘏBodyᐳ $rright = rright;
                return OptionᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }

            if( ((rright.template access<NodeᐸMainᘏBodyᐳ*>()->c != Color::Red) || (tright.template access<NodeᐸMainᘏBodyᐳ*>()->c != Color::Red)) ) {
                return OptionᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ( &None𝐓𝐲𝐩𝐞 );
            }
            NodeᐸMainᘏBodyᐳ* nl = TreeᐸMainᘏBodyᐳᘏcreateNode(Color::Black, tleft, tright.template access<NodeᐸMainᘏBodyᐳ*>()->l);
            NodeᐸMainᘏBodyᐳ* nr = TreeᐸMainᘏBodyᐳᘏcreateNode(Color::Black, rright.template access<NodeᐸMainᘏBodyᐳ*>()->l, rright.template access<NodeᐸMainᘏBodyᐳ*>()->r);
            return OptionᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ( &SomeᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ𝐓𝐲𝐩𝐞, SomeᐸListOpsᘏNodeᐸMainᘏBodyᐳᐳ( TreeᐸMainᘏBodyᐳᘏcreateNode(redden(c), TreeᐸMainᘏBodyᐳ( &NodeᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞, nl ), TreeᐸMainᘏBodyᐳ( &NodeᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞, nr ))) );
        }
        Main::Body* getᐸMainᘏBodyᐳ(TreeᐸMainᘏBodyᐳ t, __CoreCpp::Nat idx) noexcept  {
            if( t.typeinfo == &LeafᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] LeafᐸMainᘏBodyᐳ* $t = t.template access<LeafᐸMainᘏBodyᐳ*>(); 
                return $t->v;
            }
            else {
                [[maybe_unused]] TreeᐸMainᘏBodyᐳ $t = t; 
                NodeᐸMainᘏBodyᐳ* nn = t.template access<NodeᐸMainᘏBodyᐳ*>();
                __CoreCpp::Nat count = sizeᐸMainᘏBodyᐳ(nn->l);
                if( (idx < count) ) {
                    return getᐸMainᘏBodyᐳ(nn->l, idx);
                }
                else {
                    return getᐸMainᘏBodyᐳ(nn->r, (idx - count));
                }
            }
        }
        Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ pushBackᐸ丨FloatᐧFloatᐧFloat丨ᐳ(Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ t, __CoreCpp::Tuple3<1, 1, 1> v) noexcept  {
            if( t.typeinfo == &BBLeafᐸ丨FloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞 ) {
                return Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ( &Leafᐸ丨FloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞, Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳᘏcreateLeaf(v) );
            }
            Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ tt = pushBack_helperᐸ丨FloatᐧFloatᐧFloat丨ᐳ(t, v);
            if( tt.typeinfo != &Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ $tt = tt; 
                return tt;
            }
            else {
                [[maybe_unused]] Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ* $tt = tt.template access<Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ*>(); 
                Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ* nt = ( ($tt->c == Color::Red) ? (Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳᘏcreateNode(Color::Black, $tt->l, $tt->r)) : ($tt) );
                return Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ( &Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞, nt );
            }
        }
        Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ pushBackᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ(Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ t, __CoreCpp::Tuple4<1, 1, 1, 1> v) noexcept  {
            if( t.typeinfo == &BBLeafᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞 ) {
                return Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ( &Leafᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞, Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᘏcreateLeaf(v) );
            }
            Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ tt = pushBack_helperᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ(t, v);
            if( tt.typeinfo != &Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ $tt = tt; 
                return tt;
            }
            else {
                [[maybe_unused]] Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ* $tt = tt.template access<Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ*>(); 
                Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ* nt = ( ($tt->c == Color::Red) ? (Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᘏcreateNode(Color::Black, $tt->l, $tt->r)) : ($tt) );
                return Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ( &Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞, nt );
            }
        }
        Treeᐸ丨NatᐧNat丨ᐳ pushBackᐸ丨NatᐧNat丨ᐳ(Treeᐸ丨NatᐧNat丨ᐳ t, __CoreCpp::Tuple2<1, 1> v) noexcept  {
            if( t.typeinfo == &BBLeafᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞 ) {
                return Treeᐸ丨NatᐧNat丨ᐳ( &Leafᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞, Treeᐸ丨NatᐧNat丨ᐳᘏcreateLeaf(v) );
            }
            Treeᐸ丨NatᐧNat丨ᐳ tt = pushBack_helperᐸ丨NatᐧNat丨ᐳ(t, v);
            if( tt.typeinfo != &Nodeᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] Treeᐸ丨NatᐧNat丨ᐳ $tt = tt; 
                return tt;
            }
            else {
                [[maybe_unused]] Nodeᐸ丨NatᐧNat丨ᐳ* $tt = tt.template access<Nodeᐸ丨NatᐧNat丨ᐳ*>(); 
                Nodeᐸ丨NatᐧNat丨ᐳ* nt = ( ($tt->c == Color::Red) ? (Treeᐸ丨NatᐧNat丨ᐳᘏcreateNode(Color::Black, $tt->l, $tt->r)) : ($tt) );
                return Treeᐸ丨NatᐧNat丨ᐳ( &Nodeᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞, nt );
            }
        }
        TreeᐸFloatᐳ pushBackᐸFloatᐳ(TreeᐸFloatᐳ t, __CoreCpp::Float v) noexcept  {
            if( t.typeinfo == &BBLeafᐸFloatᐳ𝐓𝐲𝐩𝐞 ) {
                return TreeᐸFloatᐳ( &LeafᐸFloatᐳ𝐓𝐲𝐩𝐞, TreeᐸFloatᐳᘏcreateLeaf(v) );
            }
            TreeᐸFloatᐳ tt = pushBack_helperᐸFloatᐳ(t, v);
            if( tt.typeinfo != &NodeᐸFloatᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] TreeᐸFloatᐳ $tt = tt; 
                return tt;
            }
            else {
                [[maybe_unused]] NodeᐸFloatᐳ* $tt = tt.template access<NodeᐸFloatᐳ*>(); 
                NodeᐸFloatᐳ* nt = ( ($tt->c == Color::Red) ? (TreeᐸFloatᐳᘏcreateNode(Color::Black, $tt->l, $tt->r)) : ($tt) );
                return TreeᐸFloatᐳ( &NodeᐸFloatᐳ𝐓𝐲𝐩𝐞, nt );
            }
        }
        TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ pushBackᐸListᐸ丨NatᐧNat丨ᐳᐳ(TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ t, Listᐸ丨NatᐧNat丨ᐳ v) noexcept  {
            if( t.typeinfo == &BBLeafᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞 ) {
                return TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ( &LeafᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞, TreeᐸListᐸ丨NatᐧNat丨ᐳᐳᘏcreateLeaf(v) );
            }
            TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ tt = pushBack_helperᐸListᐸ丨NatᐧNat丨ᐳᐳ(t, v);
            if( tt.typeinfo != &NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ $tt = tt; 
                return tt;
            }
            else {
                [[maybe_unused]] NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ* $tt = tt.template access<NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ*>(); 
                NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ* nt = ( ($tt->c == Color::Red) ? (TreeᐸListᐸ丨NatᐧNat丨ᐳᐳᘏcreateNode(Color::Black, $tt->l, $tt->r)) : ($tt) );
                return TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ( &NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞, nt );
            }
        }
        TreeᐸMainᘏBodyᐳ pushBackᐸMainᘏBodyᐳ(TreeᐸMainᘏBodyᐳ t, Main::Body* v) noexcept  {
            if( t.typeinfo == &BBLeafᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞 ) {
                return TreeᐸMainᘏBodyᐳ( &LeafᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞, TreeᐸMainᘏBodyᐳᘏcreateLeaf(v) );
            }
            TreeᐸMainᘏBodyᐳ tt = pushBack_helperᐸMainᘏBodyᐳ(t, v);
            if( tt.typeinfo != &NodeᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞 ) {
                [[maybe_unused]] TreeᐸMainᘏBodyᐳ $tt = tt; 
                return tt;
            }
            else {
                [[maybe_unused]] NodeᐸMainᘏBodyᐳ* $tt = tt.template access<NodeᐸMainᘏBodyᐳ*>(); 
                NodeᐸMainᘏBodyᐳ* nt = ( ($tt->c == Color::Red) ? (TreeᐸMainᘏBodyᐳᘏcreateNode(Color::Black, $tt->l, $tt->r)) : ($tt) );
                return TreeᐸMainᘏBodyᐳ( &NodeᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞, nt );
            }
        }
        Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ pushBack_helperᐸ丨FloatᐧFloatᐧFloat丨ᐳ(Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ t, __CoreCpp::Tuple3<1, 1, 1> v) noexcept  {
            if(t.typeinfo == &Leafᐸ丨FloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞) {
                [[maybe_unused]] Leafᐸ丨FloatᐧFloatᐧFloat丨ᐳ $t = t.template access<Leafᐸ丨FloatᐧFloatᐧFloat丨ᐳ>();
                return balanceᐸ丨FloatᐧFloatᐧFloat丨ᐳ(Color::Red, Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ( &Leafᐸ丨FloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞, $t ), Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ( &Leafᐸ丨FloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞, Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳᘏcreateLeaf(v) ));
            }
            else if(t.typeinfo == &Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞) {
                [[maybe_unused]] Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ* $t = t.template access<Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ*>();
                Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ nr = pushBack_helperᐸ丨FloatᐧFloatᐧFloat丨ᐳ($t->r, v);
                return balanceᐸ丨FloatᐧFloatᐧFloat丨ᐳ($t->c, $t->l, nr);
            }
            else {
                𝐚𝐛𝐨𝐫𝐭;
            }
        }
        Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ pushBack_helperᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ(Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ t, __CoreCpp::Tuple4<1, 1, 1, 1> v) noexcept  {
            if(t.typeinfo == &Leafᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞) {
                [[maybe_unused]] Leafᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ* $t = t.template access<Leafᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ*>();
                return balanceᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ(Color::Red, Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ( &Leafᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞, $t ), Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ( &Leafᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞, Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᘏcreateLeaf(v) ));
            }
            else if(t.typeinfo == &Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞) {
                [[maybe_unused]] Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ* $t = t.template access<Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ*>();
                Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ nr = pushBack_helperᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ($t->r, v);
                return balanceᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ($t->c, $t->l, nr);
            }
            else {
                𝐚𝐛𝐨𝐫𝐭;
            }
        }
        Treeᐸ丨NatᐧNat丨ᐳ pushBack_helperᐸ丨NatᐧNat丨ᐳ(Treeᐸ丨NatᐧNat丨ᐳ t, __CoreCpp::Tuple2<1, 1> v) noexcept  {
            if(t.typeinfo == &Leafᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞) {
                [[maybe_unused]] Leafᐸ丨NatᐧNat丨ᐳ $t = t.template access<Leafᐸ丨NatᐧNat丨ᐳ>();
                return balanceᐸ丨NatᐧNat丨ᐳ(Color::Red, Treeᐸ丨NatᐧNat丨ᐳ( &Leafᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞, $t ), Treeᐸ丨NatᐧNat丨ᐳ( &Leafᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞, Treeᐸ丨NatᐧNat丨ᐳᘏcreateLeaf(v) ));
            }
            else if(t.typeinfo == &Nodeᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞) {
                [[maybe_unused]] Nodeᐸ丨NatᐧNat丨ᐳ* $t = t.template access<Nodeᐸ丨NatᐧNat丨ᐳ*>();
                Treeᐸ丨NatᐧNat丨ᐳ nr = pushBack_helperᐸ丨NatᐧNat丨ᐳ($t->r, v);
                return balanceᐸ丨NatᐧNat丨ᐳ($t->c, $t->l, nr);
            }
            else {
                𝐚𝐛𝐨𝐫𝐭;
            }
        }
        TreeᐸFloatᐳ pushBack_helperᐸFloatᐳ(TreeᐸFloatᐳ t, __CoreCpp::Float v) noexcept  {
            if(t.typeinfo == &LeafᐸFloatᐳ𝐓𝐲𝐩𝐞) {
                [[maybe_unused]] LeafᐸFloatᐳ $t = t.template access<LeafᐸFloatᐳ>();
                return balanceᐸFloatᐳ(Color::Red, TreeᐸFloatᐳ( &LeafᐸFloatᐳ𝐓𝐲𝐩𝐞, $t ), TreeᐸFloatᐳ( &LeafᐸFloatᐳ𝐓𝐲𝐩𝐞, TreeᐸFloatᐳᘏcreateLeaf(v) ));
            }
            else if(t.typeinfo == &NodeᐸFloatᐳ𝐓𝐲𝐩𝐞) {
                [[maybe_unused]] NodeᐸFloatᐳ* $t = t.template access<NodeᐸFloatᐳ*>();
                TreeᐸFloatᐳ nr = pushBack_helperᐸFloatᐳ($t->r, v);
                return balanceᐸFloatᐳ($t->c, $t->l, nr);
            }
            else {
                𝐚𝐛𝐨𝐫𝐭;
            }
        }
        TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ pushBack_helperᐸListᐸ丨NatᐧNat丨ᐳᐳ(TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ t, Listᐸ丨NatᐧNat丨ᐳ v) noexcept  {
            if(t.typeinfo == &LeafᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞) {
                [[maybe_unused]] LeafᐸListᐸ丨NatᐧNat丨ᐳᐳ* $t = t.template access<LeafᐸListᐸ丨NatᐧNat丨ᐳᐳ*>();
                return balanceᐸListᐸ丨NatᐧNat丨ᐳᐳ(Color::Red, TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ( &LeafᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞, $t ), TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ( &LeafᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞, TreeᐸListᐸ丨NatᐧNat丨ᐳᐳᘏcreateLeaf(v) ));
            }
            else if(t.typeinfo == &NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞) {
                [[maybe_unused]] NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ* $t = t.template access<NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ*>();
                TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ nr = pushBack_helperᐸListᐸ丨NatᐧNat丨ᐳᐳ($t->r, v);
                return balanceᐸListᐸ丨NatᐧNat丨ᐳᐳ($t->c, $t->l, nr);
            }
            else {
                𝐚𝐛𝐨𝐫𝐭;
            }
        }
        TreeᐸMainᘏBodyᐳ pushBack_helperᐸMainᘏBodyᐳ(TreeᐸMainᘏBodyᐳ t, Main::Body* v) noexcept  {
            if(t.typeinfo == &LeafᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞) {
                [[maybe_unused]] LeafᐸMainᘏBodyᐳ* $t = t.template access<LeafᐸMainᘏBodyᐳ*>();
                return balanceᐸMainᘏBodyᐳ(Color::Red, TreeᐸMainᘏBodyᐳ( &LeafᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞, $t ), TreeᐸMainᘏBodyᐳ( &LeafᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞, TreeᐸMainᘏBodyᐳᘏcreateLeaf(v) ));
            }
            else if(t.typeinfo == &NodeᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞) {
                [[maybe_unused]] NodeᐸMainᘏBodyᐳ* $t = t.template access<NodeᐸMainᘏBodyᐳ*>();
                TreeᐸMainᘏBodyᐳ nr = pushBack_helperᐸMainᘏBodyᐳ($t->r, v);
                return balanceᐸMainᘏBodyᐳ($t->c, $t->l, nr);
            }
            else {
                𝐚𝐛𝐨𝐫𝐭;
            }
        }
        Color redden(Color c) noexcept  {
            𝐚𝐬𝐬𝐞𝐫𝐭((c != Color::NB));
            if( c == Color::BB ) {
                return Color::Black;
            }
            else if( c == Color::Black ) {
                return Color::Red;
            }
            else if( true ) {
                return Color::NB;
            }
            else {
                𝐚𝐛𝐨𝐫𝐭;
            }
        }
        Listᐸ丨NatᐧNat丨ᐳ s_list_create_1ᐸ丨NatᐧNat丨ᐳ(__CoreCpp::Tuple2<1, 1> v1) noexcept  {
            return Treeᐸ丨NatᐧNat丨ᐳ( &Leafᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞, Treeᐸ丨NatᐧNat丨ᐳᘏcreateLeaf(v1) );
        }
        Listᐸ丨NatᐧNat丨ᐳ s_list_create_2ᐸ丨NatᐧNat丨ᐳ(__CoreCpp::Tuple2<1, 1> v1, __CoreCpp::Tuple2<1, 1> v2) noexcept  {
            return Treeᐸ丨NatᐧNat丨ᐳ( &Nodeᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞, Treeᐸ丨NatᐧNat丨ᐳᘏcreateNode(Color::Black, Treeᐸ丨NatᐧNat丨ᐳ( &Leafᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞, Treeᐸ丨NatᐧNat丨ᐳᘏcreateLeaf(v1) ), Treeᐸ丨NatᐧNat丨ᐳ( &Leafᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞, Treeᐸ丨NatᐧNat丨ᐳᘏcreateLeaf(v2) )) );
        }
        Listᐸ丨NatᐧNat丨ᐳ s_list_create_3ᐸ丨NatᐧNat丨ᐳ(__CoreCpp::Tuple2<1, 1> v1, __CoreCpp::Tuple2<1, 1> v2, __CoreCpp::Tuple2<1, 1> v3) noexcept  {
            return Treeᐸ丨NatᐧNat丨ᐳ( &Nodeᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞, Treeᐸ丨NatᐧNat丨ᐳᘏcreateNode(Color::Black, Treeᐸ丨NatᐧNat丨ᐳ( &Leafᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞, Treeᐸ丨NatᐧNat丨ᐳᘏcreateLeaf(v1) ), Treeᐸ丨NatᐧNat丨ᐳ( &Nodeᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞, Treeᐸ丨NatᐧNat丨ᐳᘏcreateNode(Color::Red, Treeᐸ丨NatᐧNat丨ᐳ( &Leafᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞, Treeᐸ丨NatᐧNat丨ᐳᘏcreateLeaf(v2) ), Treeᐸ丨NatᐧNat丨ᐳ( &Leafᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞, Treeᐸ丨NatᐧNat丨ᐳᘏcreateLeaf(v3) )) )) );
        }
        Listᐸ丨NatᐧNat丨ᐳ s_list_create_4ᐸ丨NatᐧNat丨ᐳ(__CoreCpp::Tuple2<1, 1> v1, __CoreCpp::Tuple2<1, 1> v2, __CoreCpp::Tuple2<1, 1> v3, __CoreCpp::Tuple2<1, 1> v4) noexcept  {
            return Treeᐸ丨NatᐧNat丨ᐳ( &Nodeᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞, Treeᐸ丨NatᐧNat丨ᐳᘏcreateNode(Color::Black, Treeᐸ丨NatᐧNat丨ᐳ( &Nodeᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞, Treeᐸ丨NatᐧNat丨ᐳᘏcreateNode(Color::Black, Treeᐸ丨NatᐧNat丨ᐳ( &Leafᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞, Treeᐸ丨NatᐧNat丨ᐳᘏcreateLeaf(v1) ), Treeᐸ丨NatᐧNat丨ᐳ( &Leafᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞, Treeᐸ丨NatᐧNat丨ᐳᘏcreateLeaf(v2) )) ), Treeᐸ丨NatᐧNat丨ᐳ( &Nodeᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞, Treeᐸ丨NatᐧNat丨ᐳᘏcreateNode(Color::Black, Treeᐸ丨NatᐧNat丨ᐳ( &Leafᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞, Treeᐸ丨NatᐧNat丨ᐳᘏcreateLeaf(v3) ), Treeᐸ丨NatᐧNat丨ᐳ( &Leafᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞, Treeᐸ丨NatᐧNat丨ᐳᘏcreateLeaf(v4) )) )) );
        }
        ListᐸListᐸ丨NatᐧNat丨ᐳᐳ s_list_create_4ᐸListᐸ丨NatᐧNat丨ᐳᐳ(Listᐸ丨NatᐧNat丨ᐳ v1, Listᐸ丨NatᐧNat丨ᐳ v2, Listᐸ丨NatᐧNat丨ᐳ v3, Listᐸ丨NatᐧNat丨ᐳ v4) noexcept  {
            return TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ( &NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞, TreeᐸListᐸ丨NatᐧNat丨ᐳᐳᘏcreateNode(Color::Black, TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ( &NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞, TreeᐸListᐸ丨NatᐧNat丨ᐳᐳᘏcreateNode(Color::Black, TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ( &LeafᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞, TreeᐸListᐸ丨NatᐧNat丨ᐳᐳᘏcreateLeaf(v1) ), TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ( &LeafᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞, TreeᐸListᐸ丨NatᐧNat丨ᐳᐳᘏcreateLeaf(v2) )) ), TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ( &NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞, TreeᐸListᐸ丨NatᐧNat丨ᐳᐳᘏcreateNode(Color::Black, TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ( &LeafᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞, TreeᐸListᐸ丨NatᐧNat丨ᐳᐳᘏcreateLeaf(v3) ), TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ( &LeafᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞, TreeᐸListᐸ丨NatᐧNat丨ᐳᐳᘏcreateLeaf(v4) )) )) );
        }
        ListᐸMainᘏBodyᐳ s_list_create_4ᐸMainᘏBodyᐳ(Main::Body* v1, Main::Body* v2, Main::Body* v3, Main::Body* v4) noexcept  {
            return TreeᐸMainᘏBodyᐳ( &NodeᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞, TreeᐸMainᘏBodyᐳᘏcreateNode(Color::Black, TreeᐸMainᘏBodyᐳ( &NodeᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞, TreeᐸMainᘏBodyᐳᘏcreateNode(Color::Black, TreeᐸMainᘏBodyᐳ( &LeafᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞, TreeᐸMainᘏBodyᐳᘏcreateLeaf(v1) ), TreeᐸMainᘏBodyᐳ( &LeafᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞, TreeᐸMainᘏBodyᐳᘏcreateLeaf(v2) )) ), TreeᐸMainᘏBodyᐳ( &NodeᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞, TreeᐸMainᘏBodyᐳᘏcreateNode(Color::Black, TreeᐸMainᘏBodyᐳ( &LeafᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞, TreeᐸMainᘏBodyᐳᘏcreateLeaf(v3) ), TreeᐸMainᘏBodyᐳ( &LeafᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞, TreeᐸMainᘏBodyᐳᘏcreateLeaf(v4) )) )) );
        }
        ListᐸMainᘏBodyᐳ s_list_create_5ᐸMainᘏBodyᐳ(Main::Body* v1, Main::Body* v2, Main::Body* v3, Main::Body* v4, Main::Body* v5) noexcept  {
            return TreeᐸMainᘏBodyᐳ( &NodeᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞, TreeᐸMainᘏBodyᐳᘏcreateNode(Color::Black, TreeᐸMainᘏBodyᐳ( &NodeᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞, TreeᐸMainᘏBodyᐳᘏcreateNode(Color::Black, TreeᐸMainᘏBodyᐳ( &LeafᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞, TreeᐸMainᘏBodyᐳᘏcreateLeaf(v1) ), TreeᐸMainᘏBodyᐳ( &LeafᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞, TreeᐸMainᘏBodyᐳᘏcreateLeaf(v2) )) ), TreeᐸMainᘏBodyᐳ( &NodeᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞, TreeᐸMainᘏBodyᐳᘏcreateNode(Color::Black, TreeᐸMainᘏBodyᐳ( &LeafᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞, TreeᐸMainᘏBodyᐳᘏcreateLeaf(v3) ), TreeᐸMainᘏBodyᐳ( &NodeᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞, TreeᐸMainᘏBodyᐳᘏcreateNode(Color::Red, TreeᐸMainᘏBodyᐳ( &LeafᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞, TreeᐸMainᘏBodyᐳᘏcreateLeaf(v4) ), TreeᐸMainᘏBodyᐳ( &LeafᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞, TreeᐸMainᘏBodyᐳᘏcreateLeaf(v5) )) )) )) );
        }
        Listᐸ丨FloatᐧFloatᐧFloat丨ᐳ s_list_create_emptyᐸ丨FloatᐧFloatᐧFloat丨ᐳ() noexcept  {
            return Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳᘏemptyTree();
        }
        Listᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ s_list_create_emptyᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ() noexcept  {
            return Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᘏemptyTree();
        }
        Listᐸ丨NatᐧNat丨ᐳ s_list_create_emptyᐸ丨NatᐧNat丨ᐳ() noexcept  {
            return Treeᐸ丨NatᐧNat丨ᐳᘏemptyTree();
        }
        ListᐸFloatᐳ s_list_create_emptyᐸFloatᐳ() noexcept  {
            return TreeᐸFloatᐳᘏemptyTree();
        }
        ListᐸListᐸ丨NatᐧNat丨ᐳᐳ s_list_create_emptyᐸListᐸ丨NatᐧNat丨ᐳᐳ() noexcept  {
            return TreeᐸListᐸ丨NatᐧNat丨ᐳᐳᘏemptyTree();
        }
        ListᐸMainᘏBodyᐳ s_list_create_emptyᐸMainᘏBodyᐳ() noexcept  {
            return TreeᐸMainᘏBodyᐳᘏemptyTree();
        }
        __CoreCpp::Bool s_list_emptyᐸ丨FloatᐧFloatᐧFloat丨ᐳ(Listᐸ丨FloatᐧFloatᐧFloat丨ᐳ l) noexcept  {
            return l.typeinfo == &BBLeafᐸ丨FloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞;
        }
        __CoreCpp::Bool s_list_emptyᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ(Listᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ l) noexcept  {
            return l.typeinfo == &BBLeafᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞;
        }
        __CoreCpp::Bool s_list_emptyᐸ丨NatᐧNat丨ᐳ(Listᐸ丨NatᐧNat丨ᐳ l) noexcept  {
            return l.typeinfo == &BBLeafᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞;
        }
        __CoreCpp::Bool s_list_emptyᐸFloatᐳ(ListᐸFloatᐳ l) noexcept  {
            return l.typeinfo == &BBLeafᐸFloatᐳ𝐓𝐲𝐩𝐞;
        }
        __CoreCpp::Bool s_list_emptyᐸListᐸ丨NatᐧNat丨ᐳᐳ(ListᐸListᐸ丨NatᐧNat丨ᐳᐳ l) noexcept  {
            return l.typeinfo == &BBLeafᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞;
        }
        __CoreCpp::Bool s_list_emptyᐸMainᘏBodyᐳ(ListᐸMainᘏBodyᐳ l) noexcept  {
            return l.typeinfo == &BBLeafᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞;
        }
        Main::Body* s_list_getᐸMainᘏBodyᐳ(ListᐸMainᘏBodyᐳ l, __CoreCpp::Nat idx) noexcept  {
            return getᐸMainᘏBodyᐳ(l, idx);
        }
        template <typename λfn_丨FloatᐧFloatᐧFloat丨_$Float_f>
        ListᐸFloatᐳ s_list_mapᐸ丨FloatᐧFloatᐧFloat丨ᐧFloatᐳ(Listᐸ丨FloatᐧFloatᐧFloat丨ᐳ l, λfn_丨FloatᐧFloatᐧFloat丨_$Float_f&& f) noexcept  {
            return Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳᘏmapᐸFloatᐳ(l, f);
        }
        template <typename λfn_丨BodyᐧFloatᐧFloatᐧFloat丨_$MainᘏBody_f>
        ListᐸMainᘏBodyᐳ s_list_mapᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐧMainᘏBodyᐳ(Listᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ l, λfn_丨BodyᐧFloatᐧFloatᐧFloat丨_$MainᘏBody_f&& f) noexcept  {
            return Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᘏmapᐸMainᘏBodyᐳ(l, f);
        }
        template <typename λfn_丨NatᐧNat丨_$Float_f>
        ListᐸFloatᐳ s_list_mapᐸ丨NatᐧNat丨ᐧFloatᐳ(Listᐸ丨NatᐧNat丨ᐳ l, λfn_丨NatᐧNat丨_$Float_f&& f) noexcept  {
            return Treeᐸ丨NatᐧNat丨ᐳᘏmapᐸFloatᐳ(l, f);
        }
        template <typename λfn_Listᐸ丨NatᐧNat丨ᐳ_$Float_f>
        ListᐸFloatᐳ s_list_mapᐸListᐸ丨NatᐧNat丨ᐳᐧFloatᐳ(ListᐸListᐸ丨NatᐧNat丨ᐳᐳ l, λfn_Listᐸ丨NatᐧNat丨ᐳ_$Float_f&& f) noexcept  {
            return TreeᐸListᐸ丨NatᐧNat丨ᐳᐳᘏmapᐸFloatᐳ(l, f);
        }
        template <typename λfn_Body_$丨FloatᐧFloatᐧFloat丨_f>
        Listᐸ丨FloatᐧFloatᐧFloat丨ᐳ s_list_mapᐸMainᘏBodyᐧ丨FloatᐧFloatᐧFloat丨ᐳ(ListᐸMainᘏBodyᐳ l, λfn_Body_$丨FloatᐧFloatᐧFloat丨_f&& f) noexcept  {
            return TreeᐸMainᘏBodyᐳᘏmapᐸ丨FloatᐧFloatᐧFloat丨ᐳ(l, f);
        }
        template <typename λfn_Body_$丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨_f>
        Listᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ s_list_mapᐸMainᘏBodyᐧ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ(ListᐸMainᘏBodyᐳ l, λfn_Body_$丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨_f&& f) noexcept  {
            return TreeᐸMainᘏBodyᐳᘏmapᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ(l, f);
        }
        template <typename λfn_Body_$Float_f>
        ListᐸFloatᐳ s_list_mapᐸMainᘏBodyᐧFloatᐳ(ListᐸMainᘏBodyᐳ l, λfn_Body_$Float_f&& f) noexcept  {
            return TreeᐸMainᘏBodyᐳᘏmapᐸFloatᐳ(l, f);
        }
        Listᐸ丨FloatᐧFloatᐧFloat丨ᐳ s_list_push_backᐸ丨FloatᐧFloatᐧFloat丨ᐳ(Listᐸ丨FloatᐧFloatᐧFloat丨ᐳ l, __CoreCpp::Tuple3<1, 1, 1> v) noexcept  {
            return pushBackᐸ丨FloatᐧFloatᐧFloat丨ᐳ(l, v);
        }
        Listᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ s_list_push_backᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ(Listᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ l, __CoreCpp::Tuple4<1, 1, 1, 1> v) noexcept  {
            return pushBackᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ(l, v);
        }
        Listᐸ丨NatᐧNat丨ᐳ s_list_push_backᐸ丨NatᐧNat丨ᐳ(Listᐸ丨NatᐧNat丨ᐳ l, __CoreCpp::Tuple2<1, 1> v) noexcept  {
            return pushBackᐸ丨NatᐧNat丨ᐳ(l, v);
        }
        ListᐸFloatᐳ s_list_push_backᐸFloatᐳ(ListᐸFloatᐳ l, __CoreCpp::Float v) noexcept  {
            return pushBackᐸFloatᐳ(l, v);
        }
        ListᐸListᐸ丨NatᐧNat丨ᐳᐳ s_list_push_backᐸListᐸ丨NatᐧNat丨ᐳᐳ(ListᐸListᐸ丨NatᐧNat丨ᐳᐳ l, Listᐸ丨NatᐧNat丨ᐳ v) noexcept  {
            return pushBackᐸListᐸ丨NatᐧNat丨ᐳᐳ(l, v);
        }
        ListᐸMainᘏBodyᐳ s_list_push_backᐸMainᘏBodyᐳ(ListᐸMainᘏBodyᐳ l, Main::Body* v) noexcept  {
            return pushBackᐸMainᘏBodyᐳ(l, v);
        }
        __CoreCpp::Nat s_list_sizeᐸMainᘏBodyᐳ(ListᐸMainᘏBodyᐳ l) noexcept  {
            return sizeᐸMainᘏBodyᐳ(l);
        }
        __CoreCpp::Float s_list_sumᐸFloatᐳ(ListᐸFloatᐳ l, __CoreCpp::Float zero) noexcept  {
            return TreeᐸFloatᐳᘏsum(l, zero);
        }
        __CoreCpp::Nat sizeᐸ丨FloatᐧFloatᐧFloat丨ᐳ(Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ t) noexcept  {
            if(t.typeinfo == &BBLeafᐸ丨FloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞) {
                [[maybe_unused]] BBLeafᐸ丨FloatᐧFloatᐧFloat丨ᐳ $t = t.template access<BBLeafᐸ丨FloatᐧFloatᐧFloat丨ᐳ>();
                return 0_n;
            }
            else if(t.typeinfo == &Leafᐸ丨FloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞) {
                [[maybe_unused]] Leafᐸ丨FloatᐧFloatᐧFloat丨ᐳ $t = t.template access<Leafᐸ丨FloatᐧFloatᐧFloat丨ᐳ>();
                return 1_n;
            }
            else if(t.typeinfo == &Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞) {
                [[maybe_unused]] Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ* $t = t.template access<Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ*>();
                return $t->count;
            }
            else {
                𝐚𝐛𝐨𝐫𝐭;
            }
        }
        __CoreCpp::Nat sizeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ(Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ t) noexcept  {
            if(t.typeinfo == &BBLeafᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞) {
                [[maybe_unused]] BBLeafᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ $t = t.template access<BBLeafᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ>();
                return 0_n;
            }
            else if(t.typeinfo == &Leafᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞) {
                [[maybe_unused]] Leafᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ* $t = t.template access<Leafᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ*>();
                return 1_n;
            }
            else if(t.typeinfo == &Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞) {
                [[maybe_unused]] Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ* $t = t.template access<Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ*>();
                return $t->count;
            }
            else {
                𝐚𝐛𝐨𝐫𝐭;
            }
        }
        __CoreCpp::Nat sizeᐸ丨NatᐧNat丨ᐳ(Treeᐸ丨NatᐧNat丨ᐳ t) noexcept  {
            if(t.typeinfo == &BBLeafᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞) {
                [[maybe_unused]] BBLeafᐸ丨NatᐧNat丨ᐳ $t = t.template access<BBLeafᐸ丨NatᐧNat丨ᐳ>();
                return 0_n;
            }
            else if(t.typeinfo == &Leafᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞) {
                [[maybe_unused]] Leafᐸ丨NatᐧNat丨ᐳ $t = t.template access<Leafᐸ丨NatᐧNat丨ᐳ>();
                return 1_n;
            }
            else if(t.typeinfo == &Nodeᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞) {
                [[maybe_unused]] Nodeᐸ丨NatᐧNat丨ᐳ* $t = t.template access<Nodeᐸ丨NatᐧNat丨ᐳ*>();
                return $t->count;
            }
            else {
                𝐚𝐛𝐨𝐫𝐭;
            }
        }
        __CoreCpp::Nat sizeᐸFloatᐳ(TreeᐸFloatᐳ t) noexcept  {
            if(t.typeinfo == &BBLeafᐸFloatᐳ𝐓𝐲𝐩𝐞) {
                [[maybe_unused]] BBLeafᐸFloatᐳ $t = t.template access<BBLeafᐸFloatᐳ>();
                return 0_n;
            }
            else if(t.typeinfo == &LeafᐸFloatᐳ𝐓𝐲𝐩𝐞) {
                [[maybe_unused]] LeafᐸFloatᐳ $t = t.template access<LeafᐸFloatᐳ>();
                return 1_n;
            }
            else if(t.typeinfo == &NodeᐸFloatᐳ𝐓𝐲𝐩𝐞) {
                [[maybe_unused]] NodeᐸFloatᐳ* $t = t.template access<NodeᐸFloatᐳ*>();
                return $t->count;
            }
            else {
                𝐚𝐛𝐨𝐫𝐭;
            }
        }
        __CoreCpp::Nat sizeᐸListᐸ丨NatᐧNat丨ᐳᐳ(TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ t) noexcept  {
            if(t.typeinfo == &BBLeafᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞) {
                [[maybe_unused]] BBLeafᐸListᐸ丨NatᐧNat丨ᐳᐳ $t = t.template access<BBLeafᐸListᐸ丨NatᐧNat丨ᐳᐳ>();
                return 0_n;
            }
            else if(t.typeinfo == &LeafᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞) {
                [[maybe_unused]] LeafᐸListᐸ丨NatᐧNat丨ᐳᐳ* $t = t.template access<LeafᐸListᐸ丨NatᐧNat丨ᐳᐳ*>();
                return 1_n;
            }
            else if(t.typeinfo == &NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞) {
                [[maybe_unused]] NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ* $t = t.template access<NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ*>();
                return $t->count;
            }
            else {
                𝐚𝐛𝐨𝐫𝐭;
            }
        }
        __CoreCpp::Nat sizeᐸMainᘏBodyᐳ(TreeᐸMainᘏBodyᐳ t) noexcept  {
            if(t.typeinfo == &BBLeafᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞) {
                [[maybe_unused]] BBLeafᐸMainᘏBodyᐳ $t = t.template access<BBLeafᐸMainᘏBodyᐳ>();
                return 0_n;
            }
            else if(t.typeinfo == &LeafᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞) {
                [[maybe_unused]] LeafᐸMainᘏBodyᐳ* $t = t.template access<LeafᐸMainᘏBodyᐳ*>();
                return 1_n;
            }
            else if(t.typeinfo == &NodeᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞) {
                [[maybe_unused]] NodeᐸMainᘏBodyᐳ* $t = t.template access<NodeᐸMainᘏBodyᐳ*>();
                return $t->count;
            }
            else {
                𝐚𝐛𝐨𝐫𝐭;
            }
        }
        Leafᐸ丨FloatᐧFloatᐧFloat丨ᐳ Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳᘏcreateLeaf(__CoreCpp::Tuple3<1, 1, 1> v) noexcept  {
            return Leafᐸ丨FloatᐧFloatᐧFloat丨ᐳ( v );
        }
        Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ* Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳᘏcreateNode(Color c, Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ l, Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ r) noexcept  {
            return 𝐀𝐥𝐥𝐨𝐜𝐓𝐲𝐩𝐞( Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ, alloc10, &Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞, (Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ( c, (sizeᐸ丨FloatᐧFloatᐧFloat丨ᐳ(l) + sizeᐸ丨FloatᐧFloatᐧFloat丨ᐳ(r)), l, r )) );
        }
        template <typename λfn_丨FloatᐧFloatᐧFloat丨_$Float_f>
        TreeᐸFloatᐳ Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳᘏmapᐸFloatᐳ(Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ t, λfn_丨FloatᐧFloatᐧFloat丨_$Float_f&& f) noexcept  {
            if(t.typeinfo == &BBLeafᐸ丨FloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞) {
                [[maybe_unused]] BBLeafᐸ丨FloatᐧFloatᐧFloat丨ᐳ $t = t.template access<BBLeafᐸ丨FloatᐧFloatᐧFloat丨ᐳ>();
                return TreeᐸFloatᐳ( &BBLeafᐸFloatᐳ𝐓𝐲𝐩𝐞 );
            }
            else if(t.typeinfo == &Leafᐸ丨FloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞) {
                [[maybe_unused]] Leafᐸ丨FloatᐧFloatᐧFloat丨ᐳ $t = t.template access<Leafᐸ丨FloatᐧFloatᐧFloat丨ᐳ>();
                return TreeᐸFloatᐳ( &LeafᐸFloatᐳ𝐓𝐲𝐩𝐞, LeafᐸFloatᐳ( f( $t.v ) ) );
            }
            else if(t.typeinfo == &Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞) {
                [[maybe_unused]] Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ* $t = t.template access<Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ*>();
                TreeᐸFloatᐳ nl = Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳᘏmapᐸFloatᐳ($t->l, f);
                TreeᐸFloatᐳ nr = Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳᘏmapᐸFloatᐳ($t->r, f);
                return TreeᐸFloatᐳ( &NodeᐸFloatᐳ𝐓𝐲𝐩𝐞, 𝐀𝐥𝐥𝐨𝐜𝐓𝐲𝐩𝐞( NodeᐸFloatᐳ, alloc6, &NodeᐸFloatᐳ𝐓𝐲𝐩𝐞, (NodeᐸFloatᐳ( $t->c, $t->count, nl, nr )) ) );
            }
            else {
                𝐚𝐛𝐨𝐫𝐭;
            }
        }
        Leafᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ* Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᘏcreateLeaf(__CoreCpp::Tuple4<1, 1, 1, 1> v) noexcept  {
            return 𝐀𝐥𝐥𝐨𝐜𝐓𝐲𝐩𝐞( Leafᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ, alloc4, &Leafᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞, (Leafᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ( v )) );
        }
        Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ* Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᘏcreateNode(Color c, Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ l, Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ r) noexcept  {
            return 𝐀𝐥𝐥𝐨𝐜𝐓𝐲𝐩𝐞( Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ, alloc6, &Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞, (Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ( c, (sizeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ(l) + sizeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ(r)), l, r )) );
        }
        template <typename λfn_丨BodyᐧFloatᐧFloatᐧFloat丨_$MainᘏBody_f>
        TreeᐸMainᘏBodyᐳ Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᘏmapᐸMainᘏBodyᐳ(Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ t, λfn_丨BodyᐧFloatᐧFloatᐧFloat丨_$MainᘏBody_f&& f) noexcept  {
            if(t.typeinfo == &BBLeafᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞) {
                [[maybe_unused]] BBLeafᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ $t = t.template access<BBLeafᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ>();
                return TreeᐸMainᘏBodyᐳ( &BBLeafᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞 );
            }
            else if(t.typeinfo == &Leafᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞) {
                [[maybe_unused]] Leafᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ* $t = t.template access<Leafᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ*>();
                return TreeᐸMainᘏBodyᐳ( &LeafᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞, 𝐀𝐥𝐥𝐨𝐜𝐓𝐲𝐩𝐞( LeafᐸMainᘏBodyᐳ, alloc1, &LeafᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞, (LeafᐸMainᘏBodyᐳ( f( $t->v ) )) ) );
            }
            else if(t.typeinfo == &Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞) {
                [[maybe_unused]] Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ* $t = t.template access<Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ*>();
                TreeᐸMainᘏBodyᐳ nl = Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᘏmapᐸMainᘏBodyᐳ($t->l, f);
                TreeᐸMainᘏBodyᐳ nr = Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᘏmapᐸMainᘏBodyᐳ($t->r, f);
                return TreeᐸMainᘏBodyᐳ( &NodeᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞, 𝐀𝐥𝐥𝐨𝐜𝐓𝐲𝐩𝐞( NodeᐸMainᘏBodyᐳ, alloc6, &NodeᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞, (NodeᐸMainᘏBodyᐳ( $t->c, $t->count, nl, nr )) ) );
            }
            else {
                𝐚𝐛𝐨𝐫𝐭;
            }
        }
        Leafᐸ丨NatᐧNat丨ᐳ Treeᐸ丨NatᐧNat丨ᐳᘏcreateLeaf(__CoreCpp::Tuple2<1, 1> v) noexcept  {
            return Leafᐸ丨NatᐧNat丨ᐳ( v );
        }
        Nodeᐸ丨NatᐧNat丨ᐳ* Treeᐸ丨NatᐧNat丨ᐳᘏcreateNode(Color c, Treeᐸ丨NatᐧNat丨ᐳ l, Treeᐸ丨NatᐧNat丨ᐳ r) noexcept  {
            return 𝐀𝐥𝐥𝐨𝐜𝐓𝐲𝐩𝐞( Nodeᐸ丨NatᐧNat丨ᐳ, alloc8, &Nodeᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞, (Nodeᐸ丨NatᐧNat丨ᐳ( c, (sizeᐸ丨NatᐧNat丨ᐳ(l) + sizeᐸ丨NatᐧNat丨ᐳ(r)), l, r )) );
        }
        template <typename λfn_丨NatᐧNat丨_$Float_f>
        TreeᐸFloatᐳ Treeᐸ丨NatᐧNat丨ᐳᘏmapᐸFloatᐳ(Treeᐸ丨NatᐧNat丨ᐳ t, λfn_丨NatᐧNat丨_$Float_f&& f) noexcept  {
            if(t.typeinfo == &BBLeafᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞) {
                [[maybe_unused]] BBLeafᐸ丨NatᐧNat丨ᐳ $t = t.template access<BBLeafᐸ丨NatᐧNat丨ᐳ>();
                return TreeᐸFloatᐳ( &BBLeafᐸFloatᐳ𝐓𝐲𝐩𝐞 );
            }
            else if(t.typeinfo == &Leafᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞) {
                [[maybe_unused]] Leafᐸ丨NatᐧNat丨ᐳ $t = t.template access<Leafᐸ丨NatᐧNat丨ᐳ>();
                return TreeᐸFloatᐳ( &LeafᐸFloatᐳ𝐓𝐲𝐩𝐞, LeafᐸFloatᐳ( f( $t.v ) ) );
            }
            else if(t.typeinfo == &Nodeᐸ丨NatᐧNat丨ᐳ𝐓𝐲𝐩𝐞) {
                [[maybe_unused]] Nodeᐸ丨NatᐧNat丨ᐳ* $t = t.template access<Nodeᐸ丨NatᐧNat丨ᐳ*>();
                TreeᐸFloatᐳ nl = Treeᐸ丨NatᐧNat丨ᐳᘏmapᐸFloatᐳ($t->l, f);
                TreeᐸFloatᐳ nr = Treeᐸ丨NatᐧNat丨ᐳᘏmapᐸFloatᐳ($t->r, f);
                return TreeᐸFloatᐳ( &NodeᐸFloatᐳ𝐓𝐲𝐩𝐞, 𝐀𝐥𝐥𝐨𝐜𝐓𝐲𝐩𝐞( NodeᐸFloatᐳ, alloc6, &NodeᐸFloatᐳ𝐓𝐲𝐩𝐞, (NodeᐸFloatᐳ( $t->c, $t->count, nl, nr )) ) );
            }
            else {
                𝐚𝐛𝐨𝐫𝐭;
            }
        }
        LeafᐸFloatᐳ TreeᐸFloatᐳᘏcreateLeaf(__CoreCpp::Float v) noexcept  {
            return LeafᐸFloatᐳ( v );
        }
        NodeᐸFloatᐳ* TreeᐸFloatᐳᘏcreateNode(Color c, TreeᐸFloatᐳ l, TreeᐸFloatᐳ r) noexcept  {
            return 𝐀𝐥𝐥𝐨𝐜𝐓𝐲𝐩𝐞( NodeᐸFloatᐳ, alloc6, &NodeᐸFloatᐳ𝐓𝐲𝐩𝐞, (NodeᐸFloatᐳ( c, (sizeᐸFloatᐳ(l) + sizeᐸFloatᐳ(r)), l, r )) );
        }
        __CoreCpp::Float TreeᐸFloatᐳᘏsum(TreeᐸFloatᐳ t, __CoreCpp::Float acc) noexcept  {
            if(t.typeinfo == &BBLeafᐸFloatᐳ𝐓𝐲𝐩𝐞) {
                [[maybe_unused]] BBLeafᐸFloatᐳ $t = t.template access<BBLeafᐸFloatᐳ>();
                return acc;
            }
            else if(t.typeinfo == &LeafᐸFloatᐳ𝐓𝐲𝐩𝐞) {
                [[maybe_unused]] LeafᐸFloatᐳ $t = t.template access<LeafᐸFloatᐳ>();
                return (acc + $t.v);
            }
            else if(t.typeinfo == &NodeᐸFloatᐳ𝐓𝐲𝐩𝐞) {
                [[maybe_unused]] NodeᐸFloatᐳ* $t = t.template access<NodeᐸFloatᐳ*>();
                return TreeᐸFloatᐳᘏsum($t->r, TreeᐸFloatᐳᘏsum($t->l, acc));
            }
            else {
                𝐚𝐛𝐨𝐫𝐭;
            }
        }
        LeafᐸListᐸ丨NatᐧNat丨ᐳᐳ* TreeᐸListᐸ丨NatᐧNat丨ᐳᐳᘏcreateLeaf(Listᐸ丨NatᐧNat丨ᐳ v) noexcept  {
            return 𝐀𝐥𝐥𝐨𝐜𝐓𝐲𝐩𝐞( LeafᐸListᐸ丨NatᐧNat丨ᐳᐳ, alloc3, &LeafᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞, (LeafᐸListᐸ丨NatᐧNat丨ᐳᐳ( v )) );
        }
        NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ* TreeᐸListᐸ丨NatᐧNat丨ᐳᐳᘏcreateNode(Color c, TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ l, TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ r) noexcept  {
            return 𝐀𝐥𝐥𝐨𝐜𝐓𝐲𝐩𝐞( NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ, alloc6, &NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞, (NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ( c, (sizeᐸListᐸ丨NatᐧNat丨ᐳᐳ(l) + sizeᐸListᐸ丨NatᐧNat丨ᐳᐳ(r)), l, r )) );
        }
        template <typename λfn_Listᐸ丨NatᐧNat丨ᐳ_$Float_f>
        TreeᐸFloatᐳ TreeᐸListᐸ丨NatᐧNat丨ᐳᐳᘏmapᐸFloatᐳ(TreeᐸListᐸ丨NatᐧNat丨ᐳᐳ t, λfn_Listᐸ丨NatᐧNat丨ᐳ_$Float_f&& f) noexcept  {
            if(t.typeinfo == &BBLeafᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞) {
                [[maybe_unused]] BBLeafᐸListᐸ丨NatᐧNat丨ᐳᐳ $t = t.template access<BBLeafᐸListᐸ丨NatᐧNat丨ᐳᐳ>();
                return TreeᐸFloatᐳ( &BBLeafᐸFloatᐳ𝐓𝐲𝐩𝐞 );
            }
            else if(t.typeinfo == &LeafᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞) {
                [[maybe_unused]] LeafᐸListᐸ丨NatᐧNat丨ᐳᐳ* $t = t.template access<LeafᐸListᐸ丨NatᐧNat丨ᐳᐳ*>();
                return TreeᐸFloatᐳ( &LeafᐸFloatᐳ𝐓𝐲𝐩𝐞, LeafᐸFloatᐳ( f( $t->v ) ) );
            }
            else if(t.typeinfo == &NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ𝐓𝐲𝐩𝐞) {
                [[maybe_unused]] NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ* $t = t.template access<NodeᐸListᐸ丨NatᐧNat丨ᐳᐳ*>();
                TreeᐸFloatᐳ nl = TreeᐸListᐸ丨NatᐧNat丨ᐳᐳᘏmapᐸFloatᐳ($t->l, f);
                TreeᐸFloatᐳ nr = TreeᐸListᐸ丨NatᐧNat丨ᐳᐳᘏmapᐸFloatᐳ($t->r, f);
                return TreeᐸFloatᐳ( &NodeᐸFloatᐳ𝐓𝐲𝐩𝐞, 𝐀𝐥𝐥𝐨𝐜𝐓𝐲𝐩𝐞( NodeᐸFloatᐳ, alloc6, &NodeᐸFloatᐳ𝐓𝐲𝐩𝐞, (NodeᐸFloatᐳ( $t->c, $t->count, nl, nr )) ) );
            }
            else {
                𝐚𝐛𝐨𝐫𝐭;
            }
        }
        LeafᐸMainᘏBodyᐳ* TreeᐸMainᘏBodyᐳᘏcreateLeaf(Main::Body* v) noexcept  {
            return 𝐀𝐥𝐥𝐨𝐜𝐓𝐲𝐩𝐞( LeafᐸMainᘏBodyᐳ, alloc1, &LeafᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞, (LeafᐸMainᘏBodyᐳ( v )) );
        }
        NodeᐸMainᘏBodyᐳ* TreeᐸMainᘏBodyᐳᘏcreateNode(Color c, TreeᐸMainᘏBodyᐳ l, TreeᐸMainᘏBodyᐳ r) noexcept  {
            return 𝐀𝐥𝐥𝐨𝐜𝐓𝐲𝐩𝐞( NodeᐸMainᘏBodyᐳ, alloc6, &NodeᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞, (NodeᐸMainᘏBodyᐳ( c, (sizeᐸMainᘏBodyᐳ(l) + sizeᐸMainᘏBodyᐳ(r)), l, r )) );
        }
        template <typename λfn_Body_$丨FloatᐧFloatᐧFloat丨_f>
        Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ TreeᐸMainᘏBodyᐳᘏmapᐸ丨FloatᐧFloatᐧFloat丨ᐳ(TreeᐸMainᘏBodyᐳ t, λfn_Body_$丨FloatᐧFloatᐧFloat丨_f&& f) noexcept  {
            if(t.typeinfo == &BBLeafᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞) {
                [[maybe_unused]] BBLeafᐸMainᘏBodyᐳ $t = t.template access<BBLeafᐸMainᘏBodyᐳ>();
                return Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ( &BBLeafᐸ丨FloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞 );
            }
            else if(t.typeinfo == &LeafᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞) {
                [[maybe_unused]] LeafᐸMainᘏBodyᐳ* $t = t.template access<LeafᐸMainᘏBodyᐳ*>();
                return Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ( &Leafᐸ丨FloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞, Leafᐸ丨FloatᐧFloatᐧFloat丨ᐳ( f( $t->v ) ) );
            }
            else if(t.typeinfo == &NodeᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞) {
                [[maybe_unused]] NodeᐸMainᘏBodyᐳ* $t = t.template access<NodeᐸMainᘏBodyᐳ*>();
                Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ nl = TreeᐸMainᘏBodyᐳᘏmapᐸ丨FloatᐧFloatᐧFloat丨ᐳ($t->l, f);
                Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ nr = TreeᐸMainᘏBodyᐳᘏmapᐸ丨FloatᐧFloatᐧFloat丨ᐳ($t->r, f);
                return Treeᐸ丨FloatᐧFloatᐧFloat丨ᐳ( &Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞, 𝐀𝐥𝐥𝐨𝐜𝐓𝐲𝐩𝐞( Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ, alloc10, &Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞, (Nodeᐸ丨FloatᐧFloatᐧFloat丨ᐳ( $t->c, $t->count, nl, nr )) ) );
            }
            else {
                𝐚𝐛𝐨𝐫𝐭;
            }
        }
        template <typename λfn_Body_$丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨_f>
        Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ TreeᐸMainᘏBodyᐳᘏmapᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ(TreeᐸMainᘏBodyᐳ t, λfn_Body_$丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨_f&& f) noexcept  {
            if(t.typeinfo == &BBLeafᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞) {
                [[maybe_unused]] BBLeafᐸMainᘏBodyᐳ $t = t.template access<BBLeafᐸMainᘏBodyᐳ>();
                return Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ( &BBLeafᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞 );
            }
            else if(t.typeinfo == &LeafᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞) {
                [[maybe_unused]] LeafᐸMainᘏBodyᐳ* $t = t.template access<LeafᐸMainᘏBodyᐳ*>();
                return Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ( &Leafᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞, 𝐀𝐥𝐥𝐨𝐜𝐓𝐲𝐩𝐞( Leafᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ, alloc4, &Leafᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞, (Leafᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ( f( $t->v ) )) ) );
            }
            else if(t.typeinfo == &NodeᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞) {
                [[maybe_unused]] NodeᐸMainᘏBodyᐳ* $t = t.template access<NodeᐸMainᘏBodyᐳ*>();
                Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ nl = TreeᐸMainᘏBodyᐳᘏmapᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ($t->l, f);
                Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ nr = TreeᐸMainᘏBodyᐳᘏmapᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ($t->r, f);
                return Treeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ( &Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞, 𝐀𝐥𝐥𝐨𝐜𝐓𝐲𝐩𝐞( Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ, alloc6, &Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ𝐓𝐲𝐩𝐞, (Nodeᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ( $t->c, $t->count, nl, nr )) ) );
            }
            else {
                𝐚𝐛𝐨𝐫𝐭;
            }
        }
        template <typename λfn_Body_$Float_f>
        TreeᐸFloatᐳ TreeᐸMainᘏBodyᐳᘏmapᐸFloatᐳ(TreeᐸMainᘏBodyᐳ t, λfn_Body_$Float_f&& f) noexcept  {
            if(t.typeinfo == &BBLeafᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞) {
                [[maybe_unused]] BBLeafᐸMainᘏBodyᐳ $t = t.template access<BBLeafᐸMainᘏBodyᐳ>();
                return TreeᐸFloatᐳ( &BBLeafᐸFloatᐳ𝐓𝐲𝐩𝐞 );
            }
            else if(t.typeinfo == &LeafᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞) {
                [[maybe_unused]] LeafᐸMainᘏBodyᐳ* $t = t.template access<LeafᐸMainᘏBodyᐳ*>();
                return TreeᐸFloatᐳ( &LeafᐸFloatᐳ𝐓𝐲𝐩𝐞, LeafᐸFloatᐳ( f( $t->v ) ) );
            }
            else if(t.typeinfo == &NodeᐸMainᘏBodyᐳ𝐓𝐲𝐩𝐞) {
                [[maybe_unused]] NodeᐸMainᘏBodyᐳ* $t = t.template access<NodeᐸMainᘏBodyᐳ*>();
                TreeᐸFloatᐳ nl = TreeᐸMainᘏBodyᐳᘏmapᐸFloatᐳ($t->l, f);
                TreeᐸFloatᐳ nr = TreeᐸMainᘏBodyᐳᘏmapᐸFloatᐳ($t->r, f);
                return TreeᐸFloatᐳ( &NodeᐸFloatᐳ𝐓𝐲𝐩𝐞, 𝐀𝐥𝐥𝐨𝐜𝐓𝐲𝐩𝐞( NodeᐸFloatᐳ, alloc6, &NodeᐸFloatᐳ𝐓𝐲𝐩𝐞, (NodeᐸFloatᐳ( $t->c, $t->count, nl, nr )) ) );
            }
            else {
                𝐚𝐛𝐨𝐫𝐭;
            }
        }
    }
    namespace NumericOps {
//
// Constants
//
//
// Constants
//
        __CoreCpp::Float s_floatSqrt(__CoreCpp::Float a) noexcept  {
            return __CoreCpp::Float(sqrtf64(a.get()));
        }
    }
//
// Constants
//
    inline __CoreCpp::Float Floatᘏe();
    inline __CoreCpp::Float Floatᘏone();
    inline __CoreCpp::Float Floatᘏpi();
    inline __CoreCpp::Float Floatᘏzero();
    inline __CoreCpp::Nat Natᘏone();
    inline __CoreCpp::Nat Natᘏzero();
//
// Constants
//
    inline __CoreCpp::Float Floatᘏe() { return 2.7182818284590451_f; }
    inline __CoreCpp::Float Floatᘏone() { return 1.0_f; }
    inline __CoreCpp::Float Floatᘏpi() { return 3.1415926535897931_f; }
    inline __CoreCpp::Float Floatᘏzero() { return 0.0_f; }
    inline __CoreCpp::Nat Natᘏone() { return 1_n; }
    inline __CoreCpp::Nat Natᘏzero() { return 0_n; }
    __CoreCpp::CCharBuffer CRopeIteratorᘏnext([[maybe_unused]] CRopeIterator &𝐭𝐡𝐢𝐬) noexcept {
        return 𝐭𝐡𝐢𝐬.next();
    }
    __CoreCpp::Bool CRopeIteratorᘏhasNext([[maybe_unused]] CRopeIterator &𝐭𝐡𝐢𝐬) noexcept {
        return 𝐭𝐡𝐢𝐬.hasNext();
    }
    template <typename λfn_丨FloatᐧFloatᐧFloat丨_$Float_f>
    Core::ListᐸFloatᐳ Listᐸ丨FloatᐧFloatᐧFloat丨ᐳᘏmapᐸFloatᐳ([[maybe_unused]] Listᐸ丨FloatᐧFloatᐧFloat丨ᐳ 𝐭𝐡𝐢𝐬, λfn_丨FloatᐧFloatᐧFloat丨_$Float_f&& f) noexcept {
        if( ListOps::s_list_emptyᐸ丨FloatᐧFloatᐧFloat丨ᐳ(𝐭𝐡𝐢𝐬) ) {
            return Core::ListOps::s_list_create_emptyᐸFloatᐳ();
        }
        else {
            return ListOps::s_list_mapᐸ丨FloatᐧFloatᐧFloat丨ᐧFloatᐳ(𝐭𝐡𝐢𝐬, f);
        }
    }
    template <typename λfn_丨BodyᐧFloatᐧFloatᐧFloat丨_$MainᘏBody_f>
    Core::ListᐸMainᘏBodyᐳ Listᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᘏmapᐸMainᘏBodyᐳ([[maybe_unused]] Listᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ 𝐭𝐡𝐢𝐬, λfn_丨BodyᐧFloatᐧFloatᐧFloat丨_$MainᘏBody_f&& f) noexcept {
        if( ListOps::s_list_emptyᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ(𝐭𝐡𝐢𝐬) ) {
            return Core::ListOps::s_list_create_emptyᐸMainᘏBodyᐳ();
        }
        else {
            return ListOps::s_list_mapᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐧMainᘏBodyᐳ(𝐭𝐡𝐢𝐬, f);
        }
    }
    template <typename λfn_丨NatᐧNat丨_$Float_f>
    Core::ListᐸFloatᐳ Listᐸ丨NatᐧNat丨ᐳᘏmapᐸFloatᐳ([[maybe_unused]] Listᐸ丨NatᐧNat丨ᐳ 𝐭𝐡𝐢𝐬, λfn_丨NatᐧNat丨_$Float_f&& f) noexcept {
        if( ListOps::s_list_emptyᐸ丨NatᐧNat丨ᐳ(𝐭𝐡𝐢𝐬) ) {
            return Core::ListOps::s_list_create_emptyᐸFloatᐳ();
        }
        else {
            return ListOps::s_list_mapᐸ丨NatᐧNat丨ᐧFloatᐳ(𝐭𝐡𝐢𝐬, f);
        }
    }
    __CoreCpp::Float ListᐸFloatᐳᘏsum([[maybe_unused]] ListᐸFloatᐳ 𝐭𝐡𝐢𝐬) noexcept {
        if( ListOps::s_list_emptyᐸFloatᐳ(𝐭𝐡𝐢𝐬) ) {
            return 0.0_f;
        }
        else {
            return ListOps::s_list_sumᐸFloatᐳ(𝐭𝐡𝐢𝐬, 0.0_f);
        }
    }
    template <typename λfn_Listᐸ丨NatᐧNat丨ᐳ_$Float_f>
    Core::ListᐸFloatᐳ ListᐸListᐸ丨NatᐧNat丨ᐳᐳᘏmapᐸFloatᐳ([[maybe_unused]] ListᐸListᐸ丨NatᐧNat丨ᐳᐳ 𝐭𝐡𝐢𝐬, λfn_Listᐸ丨NatᐧNat丨ᐳ_$Float_f&& f) noexcept {
        if( ListOps::s_list_emptyᐸListᐸ丨NatᐧNat丨ᐳᐳ(𝐭𝐡𝐢𝐬) ) {
            return Core::ListOps::s_list_create_emptyᐸFloatᐳ();
        }
        else {
            return ListOps::s_list_mapᐸListᐸ丨NatᐧNat丨ᐳᐧFloatᐳ(𝐭𝐡𝐢𝐬, f);
        }
    }
    __CoreCpp::Nat ListᐸMainᘏBodyᐳᘏsize([[maybe_unused]] ListᐸMainᘏBodyᐳ 𝐭𝐡𝐢𝐬) noexcept {
        return ListOps::s_list_sizeᐸMainᘏBodyᐳ(𝐭𝐡𝐢𝐬);
    }
    Main::Body* ListᐸMainᘏBodyᐳᘏget([[maybe_unused]] ListᐸMainᘏBodyᐳ 𝐭𝐡𝐢𝐬, __CoreCpp::Nat i) noexcept {
        𝐫𝐞𝐪𝐮𝐢𝐫𝐞𝐬((i < ListᐸMainᘏBodyᐳᘏsize(𝐭𝐡𝐢𝐬)));
        return ListOps::s_list_getᐸMainᘏBodyᐳ(𝐭𝐡𝐢𝐬, i);
    }
    template <typename λfn_Body_$Float_f>
    Core::ListᐸFloatᐳ ListᐸMainᘏBodyᐳᘏmapᐸFloatᐳ([[maybe_unused]] ListᐸMainᘏBodyᐳ 𝐭𝐡𝐢𝐬, λfn_Body_$Float_f&& f) noexcept {
        if( ListOps::s_list_emptyᐸMainᘏBodyᐳ(𝐭𝐡𝐢𝐬) ) {
            return Core::ListOps::s_list_create_emptyᐸFloatᐳ();
        }
        else {
            return ListOps::s_list_mapᐸMainᘏBodyᐧFloatᐳ(𝐭𝐡𝐢𝐬, f);
        }
    }
    template <typename λfn_Body_$丨FloatᐧFloatᐧFloat丨_f>
    Core::Listᐸ丨FloatᐧFloatᐧFloat丨ᐳ ListᐸMainᘏBodyᐳᘏmapᐸ丨FloatᐧFloatᐧFloat丨ᐳ([[maybe_unused]] ListᐸMainᘏBodyᐳ 𝐭𝐡𝐢𝐬, λfn_Body_$丨FloatᐧFloatᐧFloat丨_f&& f) noexcept {
        if( ListOps::s_list_emptyᐸMainᘏBodyᐳ(𝐭𝐡𝐢𝐬) ) {
            return Core::ListOps::s_list_create_emptyᐸ丨FloatᐧFloatᐧFloat丨ᐳ();
        }
        else {
            return ListOps::s_list_mapᐸMainᘏBodyᐧ丨FloatᐧFloatᐧFloat丨ᐳ(𝐭𝐡𝐢𝐬, f);
        }
    }
    template <typename λfn_Body_$丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨_f>
    Core::Listᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ ListᐸMainᘏBodyᐳᘏmapᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ([[maybe_unused]] ListᐸMainᘏBodyᐳ 𝐭𝐡𝐢𝐬, λfn_Body_$丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨_f&& f) noexcept {
        if( ListOps::s_list_emptyᐸMainᘏBodyᐳ(𝐭𝐡𝐢𝐬) ) {
            return Core::ListOps::s_list_create_emptyᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ();
        }
        else {
            return ListOps::s_list_mapᐸMainᘏBodyᐧ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ(𝐭𝐡𝐢𝐬, f);
        }
    }
    __CoreCpp::Nat CCharBufferᘏsize([[maybe_unused]] __CoreCpp::CCharBuffer 𝐭𝐡𝐢𝐬) noexcept {
        return CCharBufferOps::size(𝐭𝐡𝐢𝐬);
    }
    CRopeIterator CRopeIteratorᘏinitialize(CRopeOps::Rope r) noexcept  {
        return __CoreCpp::CRopeIterator{ r };
    }
    __CoreCpp::Float Floatᘏsqrt(__CoreCpp::Float x) noexcept  {
        𝐫𝐞𝐪𝐮𝐢𝐫𝐞𝐬((x >= 0.0_f));
        return NumericOps::s_floatSqrt(x);
    }
    __CoreCpp::Float Floatᘏsquare(__CoreCpp::Float x) noexcept  {
        return (x * x);
    }
}
namespace Main {
//
// Constants
//
    inline __CoreCpp::Float Bodyᘏdays_per_year();
    inline Body* Bodyᘏjupiter();
    inline Body* Bodyᘏneptune();
    inline Body* Bodyᘏsaturn();
    inline __CoreCpp::Float Bodyᘏsolar_mass();
    inline Body* Bodyᘏsun();
    inline Body* Bodyᘏuranus();
    inline Core::ListᐸListᐸ丨NatᐧNat丨ᐳᐳ NBodySystemᘏenergypairs();
//
// Constants
//
    inline __CoreCpp::Float Bodyᘏdays_per_year() { return 365.24_f; }
    inline Body* Bodyᘏjupiter() { return 𝐀𝐥𝐥𝐨𝐜𝐓𝐲𝐩𝐞( Body, alloc10, &Body𝐓𝐲𝐩𝐞, (Body( []() -> Core::CRope { const __CoreCpp::CChar* str = reinterpret_cast<const __CoreCpp::CChar*>("jupiter"); return Core::CRopeOps::s_crope_create(__CoreCpp::cbufferFromStringLiteral(0, 7, str)); }(), (0.000954791938424326609_f * Bodyᘏsolar_mass()), Position( 4.84143144246472090_f, -1.16032004402742839_f, -0.103622044471123109_f ), Velocity( (0.00166007664274403694_f * 365.24_f), (0.00769901118419740425_f * 365.24_f), (-0.0000690460016972063023_f * 365.24_f) ) )) ); }
    inline Body* Bodyᘏneptune() { return 𝐀𝐥𝐥𝐨𝐜𝐓𝐲𝐩𝐞( Body, alloc10, &Body𝐓𝐲𝐩𝐞, (Body( []() -> Core::CRope { const __CoreCpp::CChar* str = reinterpret_cast<const __CoreCpp::CChar*>("neptune"); return Core::CRopeOps::s_crope_create(__CoreCpp::cbufferFromStringLiteral(0, 7, str)); }(), (0.0000515138902046611451_f * Bodyᘏsolar_mass()), Position( 15.3796971148509165_f, -25.9193146099879641_f, 0.179258772950371181_f ), Velocity( (0.00268067772490389322_f * 365.24_f), (0.00162824170038242295_f * 365.24_f), (-0.0000951592254519715870_f * 365.24_f) ) )) ); }
    inline Body* Bodyᘏsaturn() { return 𝐀𝐥𝐥𝐨𝐜𝐓𝐲𝐩𝐞( Body, alloc10, &Body𝐓𝐲𝐩𝐞, (Body( []() -> Core::CRope { const __CoreCpp::CChar* str = reinterpret_cast<const __CoreCpp::CChar*>("saturn"); return Core::CRopeOps::s_crope_create(__CoreCpp::cbufferFromStringLiteral(0, 6, str)); }(), (0.000285885980666130812_f * Bodyᘏsolar_mass()), Position( 8.34336671824457987_f, 4.12479856412430479_f, -0.403523417114321381_f ), Velocity( (-0.00276742510726862411_f * 365.24_f), (0.00499852801234917238_f * 365.24_f), (0.0000230417297573763929_f * 365.24_f) ) )) ); }
    inline __CoreCpp::Float Bodyᘏsolar_mass() { return ((4.0_f * 3.1415926535897931_f) * 3.1415926535897931_f); }
    inline Body* Bodyᘏsun() { return 𝐀𝐥𝐥𝐨𝐜𝐓𝐲𝐩𝐞( Body, alloc10, &Body𝐓𝐲𝐩𝐞, (Body( []() -> Core::CRope { const __CoreCpp::CChar* str = reinterpret_cast<const __CoreCpp::CChar*>("sun"); return Core::CRopeOps::s_crope_create(__CoreCpp::cbufferFromStringLiteral(0, 3, str)); }(), Bodyᘏsolar_mass(), Position( 0.0_f, 0.0_f, 0.0_f ), Velocity( 0.0_f, 0.0_f, 0.0_f ) )) ); }
    inline Body* Bodyᘏuranus() { return 𝐀𝐥𝐥𝐨𝐜𝐓𝐲𝐩𝐞( Body, alloc10, &Body𝐓𝐲𝐩𝐞, (Body( []() -> Core::CRope { const __CoreCpp::CChar* str = reinterpret_cast<const __CoreCpp::CChar*>("uranus"); return Core::CRopeOps::s_crope_create(__CoreCpp::cbufferFromStringLiteral(0, 6, str)); }(), (0.0000436624404335156298_f * Bodyᘏsolar_mass()), Position( 12.8943695621391310_f, -15.1111514016986312_f, -0.223307578892655734_f ), Velocity( (0.00296460137564761618_f * 365.24_f), (0.00237847173959480950_f * 365.24_f), (-0.0000296589568540237556_f * 365.24_f) ) )) ); }
    inline Core::ListᐸListᐸ丨NatᐧNat丨ᐳᐳ NBodySystemᘏenergypairs() { return Core::ListOps::s_list_create_4ᐸListᐸ丨NatᐧNat丨ᐳᐳ(Core::ListOps::s_list_create_4ᐸ丨NatᐧNat丨ᐳ(__CoreCpp::Tuple2<1, 1>(0_n, 1_n), __CoreCpp::Tuple2<1, 1>(0_n, 2_n), __CoreCpp::Tuple2<1, 1>(0_n, 3_n), __CoreCpp::Tuple2<1, 1>(0_n, 4_n)), Core::ListOps::s_list_create_3ᐸ丨NatᐧNat丨ᐳ(__CoreCpp::Tuple2<1, 1>(1_n, 2_n), __CoreCpp::Tuple2<1, 1>(1_n, 3_n), __CoreCpp::Tuple2<1, 1>(1_n, 4_n)), Core::ListOps::s_list_create_2ᐸ丨NatᐧNat丨ᐳ(__CoreCpp::Tuple2<1, 1>(2_n, 3_n), __CoreCpp::Tuple2<1, 1>(2_n, 4_n)), Core::ListOps::s_list_create_1ᐸ丨NatᐧNat丨ᐳ(__CoreCpp::Tuple2<1, 1>(3_n, 4_n))); }
    Main::Body* BodyᘏoffsetMomentum([[maybe_unused]] Body* 𝐭𝐡𝐢𝐬, __CoreCpp::Float px, __CoreCpp::Float py, __CoreCpp::Float pz) noexcept {
        return 𝐀𝐥𝐥𝐨𝐜𝐓𝐲𝐩𝐞( Body, alloc10, &Body𝐓𝐲𝐩𝐞, (Body( 𝐭𝐡𝐢𝐬->name, 𝐭𝐡𝐢𝐬->mass, 𝐭𝐡𝐢𝐬->pos, Velocity( (-px / Bodyᘏsolar_mass()), (-py / Bodyᘏsolar_mass()), (-pz / Bodyᘏsolar_mass()) ) )) );
    }
    __CoreCpp::Float BodyᘏkineticEnergy([[maybe_unused]] Body* 𝐭𝐡𝐢𝐬) noexcept {
        return ((0.5_f * 𝐭𝐡𝐢𝐬->mass) * ((Core::Floatᘏsquare(𝐭𝐡𝐢𝐬->vel.vx) + Core::Floatᘏsquare(𝐭𝐡𝐢𝐬->vel.vy)) + Core::Floatᘏsquare(𝐭𝐡𝐢𝐬->vel.vz)));
    }
    __CoreCpp::Float NBodySystemᘏpotentialEnergyCompute([[maybe_unused]] NBodySystem* 𝐭𝐡𝐢𝐬, Core::Listᐸ丨NatᐧNat丨ᐳ ppairs) noexcept {
        Core::ListᐸFloatᐳ potentialEnergies = Core::Listᐸ丨NatᐧNat丨ᐳᘏmapᐸFloatᐳ(ppairs, [&](__CoreCpp::Tuple2<1, 1> bp) -> __CoreCpp::Float{     Body* b0 = Core::ListᐸMainᘏBodyᐳᘏget(𝐭𝐡𝐢𝐬->bodies, bp.access<__CoreCpp::Nat, 0>());
    Body* b1 = Core::ListᐸMainᘏBodyᐳᘏget(𝐭𝐡𝐢𝐬->bodies, bp.access<__CoreCpp::Nat, 1>());
    return ((b0->mass * b1->mass) / Bodyᘏdistance(b0, b1));
 });
        return Core::ListᐸFloatᐳᘏsum(potentialEnergies);
    }
    __CoreCpp::Float NBodySystemᘏenergy([[maybe_unused]] NBodySystem* 𝐭𝐡𝐢𝐬) noexcept {
        Core::ListᐸFloatᐳ keneticEnergies = Core::ListᐸMainᘏBodyᐳᘏmapᐸFloatᐳ(𝐭𝐡𝐢𝐬->bodies, [&](Body* b) -> __CoreCpp::Float{ return BodyᘏkineticEnergy(b); });
        Core::ListᐸFloatᐳ potentialEnergies = Core::ListᐸListᐸ丨NatᐧNat丨ᐳᐳᘏmapᐸFloatᐳ(NBodySystemᘏenergypairs(), [&](Core::Listᐸ丨NatᐧNat丨ᐳ pep) -> __CoreCpp::Float{     return NBodySystemᘏpotentialEnergyCompute(𝐭𝐡𝐢𝐬, pep);
 });
        return (Core::ListᐸFloatᐳᘏsum(keneticEnergies) - Core::ListᐸFloatᐳᘏsum(potentialEnergies));
    }
    Main::NBodySystem* NBodySystemᘏadvance([[maybe_unused]] NBodySystem* 𝐭𝐡𝐢𝐬, __CoreCpp::Float dt) noexcept {
        Core::Listᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ deltav = Core::ListᐸMainᘏBodyᐳᘏmapᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳ(𝐭𝐡𝐢𝐬->bodies, [&](Body* b) -> __CoreCpp::Tuple4<1, 1, 1, 1>{     Core::Listᐸ丨FloatᐧFloatᐧFloat丨ᐳ forces = Core::ListᐸMainᘏBodyᐳᘏmapᐸ丨FloatᐧFloatᐧFloat丨ᐳ(𝐭𝐡𝐢𝐬->bodies, [&](Body* ob) -> __CoreCpp::Tuple3<1, 1, 1>{     if( (b->name == ob->name) ) {
        return __CoreCpp::Tuple3<1, 1, 1>(0.0_f, 0.0_f, 0.0_f);
    }
    else {
        __CoreCpp::Float dx = (ob->pos.x - b->pos.x);
        __CoreCpp::Float dy = (ob->pos.y - b->pos.y);
        __CoreCpp::Float dz = (ob->pos.z - b->pos.z);
        __CoreCpp::Float distance = Bodyᘏdistance(ob, b);
        __CoreCpp::Float mag = (dt / ((distance * distance) * distance));
        return __CoreCpp::Tuple3<1, 1, 1>(((dx * ob->mass) * mag), ((dy * ob->mass) * mag), ((dz * ob->mass) * mag));
    }
 });
    __CoreCpp::Float fx = (b->vel.vx + Core::ListᐸFloatᐳᘏsum(Core::Listᐸ丨FloatᐧFloatᐧFloat丨ᐳᘏmapᐸFloatᐳ(forces, [&](__CoreCpp::Tuple3<1, 1, 1> fv) -> __CoreCpp::Float{ return fv.access<__CoreCpp::Float, 0>(); })));
    __CoreCpp::Float fy = (b->vel.vy + Core::ListᐸFloatᐳᘏsum(Core::Listᐸ丨FloatᐧFloatᐧFloat丨ᐳᘏmapᐸFloatᐳ(forces, [&](__CoreCpp::Tuple3<1, 1, 1> fv) -> __CoreCpp::Float{ return fv.access<__CoreCpp::Float, 1>(); })));
    __CoreCpp::Float fz = (b->vel.vz + Core::ListᐸFloatᐳᘏsum(Core::Listᐸ丨FloatᐧFloatᐧFloat丨ᐳᘏmapᐸFloatᐳ(forces, [&](__CoreCpp::Tuple3<1, 1, 1> fv) -> __CoreCpp::Float{ return fv.access<__CoreCpp::Float, 2>(); })));
    return __CoreCpp::Tuple4<1, 1, 1, 1>(b, fx, fy, fz);
 });
        Core::ListᐸMainᘏBodyᐳ bodies = Core::Listᐸ丨MainᘏBodyᐧFloatᐧFloatᐧFloat丨ᐳᘏmapᐸMainᘏBodyᐳ(deltav, [&](__CoreCpp::Tuple4<1, 1, 1, 1> utuple) -> Body*{     Body* b = utuple.access<Body*, 0>();
    __CoreCpp::Float nvx = utuple.access<__CoreCpp::Float, 1>();
    __CoreCpp::Float nvy = utuple.access<__CoreCpp::Float, 2>();
    __CoreCpp::Float nvz = utuple.access<__CoreCpp::Float, 3>();
    Velocity nvel = Velocity( nvx, nvy, nvz );
    __CoreCpp::Float nx = (b->pos.x + (nvx * dt));
    __CoreCpp::Float ny = (b->pos.y + (nvy * dt));
    __CoreCpp::Float nz = (b->pos.z + (nvz * dt));
    Position npos = Position( nx, ny, nz );
    return 𝐀𝐥𝐥𝐨𝐜𝐓𝐲𝐩𝐞( Body, alloc10, &Body𝐓𝐲𝐩𝐞, (Body( b->name, b->mass, npos, nvel )) );
 });
        return 𝐀𝐥𝐥𝐨𝐜𝐓𝐲𝐩𝐞( NBodySystem, alloc2, &NBodySystem𝐓𝐲𝐩𝐞, (NBodySystem( bodies )) );
    }
    __CoreCpp::Float main() noexcept  {
        NBodySystem* system = NBodySystemᘏcreate();
        __CoreCpp::Float step = 0.01_f;
        system = NBodySystemᘏadvance(system, step);
        system = NBodySystemᘏadvance(system, step);
        system = NBodySystemᘏadvance(system, step);
        return NBodySystemᘏenergy(system);
    }
    __CoreCpp::Float Bodyᘏdistance(Body* b0, Body* b1) noexcept  {
        __CoreCpp::Float dx = (b0->pos.x - b1->pos.x);
        __CoreCpp::Float dy = (b0->pos.y - b1->pos.y);
        __CoreCpp::Float dz = (b0->pos.z - b1->pos.z);
        return Core::Floatᘏsqrt(((Core::Floatᘏsquare(dx) + Core::Floatᘏsquare(dy)) + Core::Floatᘏsquare(dz)));
    }
    NBodySystem* NBodySystemᘏcreate() noexcept  {
        Core::ListᐸMainᘏBodyᐳ planets = Core::ListOps::s_list_create_4ᐸMainᘏBodyᐳ(Bodyᘏjupiter(), Bodyᘏsaturn(), Bodyᘏuranus(), Bodyᘏneptune());
        __CoreCpp::Float px = Core::ListᐸFloatᐳᘏsum(Core::ListᐸMainᘏBodyᐳᘏmapᐸFloatᐳ(planets, [&](Body* p) -> __CoreCpp::Float{ return (p->vel.vx * p->mass); }));
        __CoreCpp::Float py = Core::ListᐸFloatᐳᘏsum(Core::ListᐸMainᘏBodyᐳᘏmapᐸFloatᐳ(planets, [&](Body* p) -> __CoreCpp::Float{ return (p->vel.vy * p->mass); }));
        __CoreCpp::Float pz = Core::ListᐸFloatᐳᘏsum(Core::ListᐸMainᘏBodyᐳᘏmapᐸFloatᐳ(planets, [&](Body* p) -> __CoreCpp::Float{ return (p->vel.vz * p->mass); }));
        Core::ListᐸMainᘏBodyᐳ allbodies = Core::ListOps::s_list_create_5ᐸMainᘏBodyᐳ(BodyᘏoffsetMomentum(Bodyᘏsun(), px, py, pz), Bodyᘏjupiter(), Bodyᘏsaturn(), Bodyᘏuranus(), Bodyᘏneptune());
        return 𝐀𝐥𝐥𝐨𝐜𝐓𝐲𝐩𝐞( NBodySystem, alloc2, &NBodySystem𝐓𝐲𝐩𝐞, (NBodySystem( allbodies )) );
    }
}


// Prevents longjmp clobbering rbp in the gc
int wrap_setjmp() {
    if(setjmp(__CoreCpp::info.error_handler)) { 
        // We may want to pass in some source info here and perhaps expression causing failure
        std::cout << "Assertion failed! Or perhaps over/underflow?" << std::endl;
        return EXIT_FAILURE;
    }

    gtl_info.initializeGC<sizeof(allocs) / sizeof(allocs[0])>(allocs);

    // Calling our emitted main is hardcoded for now
    __CoreCpp::MainType ret = Main::main();
    std::cout << __CoreCpp::to_string(ret) << std::endl;

    return 0;
}

int main() {
    INIT_LOCKS();   
    InitBSQMemoryTheadLocalInfo();

    return wrap_setjmp();
}
