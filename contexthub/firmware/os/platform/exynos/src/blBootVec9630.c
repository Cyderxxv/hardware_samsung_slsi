
// Boot vector
const struct BlVecTable __attribute__ ((section(".blvec"))) __BL_VECTORS = {
    /* cortex requirements */
    .blStackTop = (uint32_t) &__stack_top,
    .blEntry = &__blEntry,
    .blNmiHandler = &defaultHandler,
    .blHardFaultHandler = &defaultHandler,
    .blMmuFaultHandler = &defaultHandler,
    .blBusFaultHandler = &defaultHandler,
    .blUsageFaultHandler = &defaultHandler,
    .reservedHandler7 = &defaultHandler,
    .reservedHandler8 = &defaultHandler,
    .reservedHandler9 = &defaultHandler,
    .reservedHandler10 = &defaultHandler,
    .blSvcCallHandler = &defaultHandler,
    .reservedHandler12 = &defaultHandler,
    .reservedHandler13 = &defaultHandler,
    .blPendSvHandler = &defaultHandler,
    .blSysTickHandler = &defaultHandler,

    /* soc requirements */
    .isr0 = &defaultHandler,
    .isr1 = &defaultHandler,
    .isr2 = &defaultHandler,
    .isr3 = &defaultHandler,
    .isr4 = &defaultHandler,
    .isr5 = &defaultHandler,
    .isr6 = &defaultHandler,
    .isr7 = &defaultHandler,
    .isr8 = &defaultHandler,
    .isr9 = &mailboxApHandler,
    .isr10 = &defaultHandler,
#ifdef FULL_BL
    .isr11 = &mailboxApmHandler,
#endif
    .isr12 = &defaultHandler,
    .isr13 = &defaultHandler,
    .isr14 = &defaultHandler,
    .isr15 = &defaultHandler,
    .isr16 = &defaultHandler,
    .isr17 = &defaultHandler,
    .isr18 = &defaultHandler,
    .isr19 = &defaultHandler,
    .isr20 = &defaultHandler,
    .isr21 = &defaultHandler,
    .isr22 = &defaultHandler,
    .isr23 = &defaultHandler,
    .isr24 = &defaultHandler,
    .isr25 = &defaultHandler,
    .isr26 = &defaultHandler,
    .isr27 = &defaultHandler,
    .isr28 = &defaultHandler,
    .isr29 = &defaultHandler,
    .isr30 = &defaultHandler,
    .isr31 = &defaultHandler,
    .isr32 = &defaultHandler,
    .isr33 = &defaultHandler,
    .isr34 = &defaultHandler,
    .isr35 = &defaultHandler,
    .isr36 = &defaultHandler,
    .isr37 = &defaultHandler,
    .isr38 = &defaultHandler,
    .isr39 = &defaultHandler,
    .isr40 = &defaultHandler,
    .isr41 = &defaultHandler,
    .isr42 = &defaultHandler,
    .isr43 = &defaultHandler,
};

