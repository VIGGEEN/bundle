#include <cassert>
#include "bundle.hpp"

int main() {
    using namespace bundle;
    using namespace std;

    // 23 mb dataset
    string original( "There's a lady who's sure all that glitters is gold" );
    for (int i = 0; i < 18; ++i) original += original + string( i + 1, 32 + i );

    // pack, unpack & verify all encoders
    vector<unsigned> libs { 
        RAW, SHOCO, LZ4F, MINIZ, LZIP, LZMA20,
        ZPAQ, LZ4, BROTLI9, ZSTD, LZMA25,
        BSC, BROTLI11, SHRINKER, CSC20, BCM,
        ZLING, MCM, TANGELO, ZMOLLY, CRUSH, LZJB
    };
    for( auto &lib : libs ) {
        string packed = pack(lib, original);
        string unpacked = unpack(packed);
        cout << original.size() << " -> " << packed.size() << " bytes (" << name_of(lib) << ")" << endl;
        assert( original == unpacked );
    }

    cout << "All ok." << endl;
}
