#include "systemc.h"

SC_MODULE(mux) {
    sc_in<sc_int<16>> entry1, entry2;
    sc_in<bool> UlaOP;
    sc_out<sc_int<16>> out;

    // methods
    void select();

    SC_CTOR(mux) {
        SC_METHOD(select);
        sensitive << UlaOP;
    }
}

void mux::select() {
    if (UlaOP.read()) {
        out.write(entry1.read());
    }
    else {
        out.write(entry2.read());
    }
}