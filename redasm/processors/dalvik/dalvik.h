#ifndef DALVIK_H
#define DALVIK_H

// http://pallergabor.uw.hu/androidblog/dalvik_opcodes.html
#include "../../plugins/plugins.h"

#define DEX_DECLARE_DECODE(opcode) bool decode##opcode(Buffer& buffer, const InstructionPtr& instruction) const

#define DEX_DECLARE_DECODES(op) DEX_DECLARE_DECODE(op##0); DEX_DECLARE_DECODE(op##1); DEX_DECLARE_DECODE(op##2); DEX_DECLARE_DECODE(op##3); \
                                DEX_DECLARE_DECODE(op##4); DEX_DECLARE_DECODE(op##5); DEX_DECLARE_DECODE(op##6); DEX_DECLARE_DECODE(op##7); \
                                DEX_DECLARE_DECODE(op##8); DEX_DECLARE_DECODE(op##9); DEX_DECLARE_DECODE(op##A); DEX_DECLARE_DECODE(op##B); \
                                DEX_DECLARE_DECODE(op##C); DEX_DECLARE_DECODE(op##D); DEX_DECLARE_DECODE(op##E); DEX_DECLARE_DECODE(op##F)

namespace REDasm {

class DalvikProcessor : public ProcessorPlugin
{
    private:
        typedef std::function<bool(Buffer&, const InstructionPtr&)> DecodeCallback;

    public:
        DalvikProcessor();
        virtual const char* name() const;
        virtual Printer* createPrinter(DisassemblerFunctions *disassembler, SymbolTable *symboltable) const;
        virtual bool decode(Buffer buffer, const InstructionPtr &instruction);

    private:
        bool decodeInvoke(Buffer& buffer, const InstructionPtr& instruction, const std::string& kind) const;

    private:
        DEX_DECLARE_DECODES(0);
        DEX_DECLARE_DECODES(1);
        DEX_DECLARE_DECODES(2);
        DEX_DECLARE_DECODES(3);
        DEX_DECLARE_DECODES(4);
        DEX_DECLARE_DECODES(5);
        DEX_DECLARE_DECODES(6);
        DEX_DECLARE_DECODES(7);
        DEX_DECLARE_DECODES(8);
        DEX_DECLARE_DECODES(9);
        DEX_DECLARE_DECODES(A);
        DEX_DECLARE_DECODES(B);
        DEX_DECLARE_DECODES(C);
        DEX_DECLARE_DECODES(D);
        DEX_DECLARE_DECODES(E);
        DEX_DECLARE_DECODES(F);

    private:
        std::unordered_map<u8, DecodeCallback> _opcodemap;

};

DECLARE_PROCESSOR_PLUGIN(DalvikProcessor, dalvik)

} // namespace REDasm

#endif // DALVIK_H