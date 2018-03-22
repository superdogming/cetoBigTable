#ifndef CETO_MEM_TABLE_SL_HPP
#define CETO_MEM_TABLE_SL_HPP
#include "cetoSkipList.hpp"
#include "cetoMemAllocator.hpp"
#include "cetoMemTable.hpp"
namespace ceto
{
    enum ValueType
    {
        ENUM_TYPE_ADD = 0x0,
        ENUM_TYPE_DEL = 0x1,
    };


    class QueryKey
    {
        const UINT32 QUERYKEY_BUF_LEN = 0;
        QueryKey(const BinData&userKey, UINT64 sequenceNumber,
                 ValueType type = ENUM_TYPE_ADD);
        BinData userKey() const;
        BinData internalKey() const;
        BinData memKey() const;
    private:
        CHAR* _memKeyStart;
        CHAR* _userKeyStart;
        CHAR* _end;
        CHAR _buf[QUERYKEY_BUF_LEN];
    };

    // CetoMemTableSL define
    class CetoMemTableSL: public CetoMemTable
    {
    public:
        typedef CHAR* KeyType;

        // MemTableSLKeyComparator define
        struct MemTableSLKeyComparator
        {
            INT32 operator ()(const KeyType &lhs, const KeyType &rhs);
        };
        CetoMemTableSL();
        ~CetoMemTableSL();
        virtual STATUS insert(UINT64 sequenceNumber,
                              const BinData& key, ValueType type,
                              const BinData& value);
        virtual STATUS query(const QueryKey& key, BinData& value);
    private:
        MemAllocator _allocator;
        typedef SkipList<KeyType,
            MemAllocator, MemTableSLKeyComparator> INTELNALLIST;
        INTELNALLIST _list;
    };
}
#endif