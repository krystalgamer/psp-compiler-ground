#include "common.h"
#include "rb/rs4_main/scert/scert.h"

int rt_upnp_xml_create_parser(void) {
    return 4;
}

int rt_upnp_xml_destroy_parser(void) {
    return 4;
}

int rt_upnp_xml_parse(void) {
    return 4;
}

int rt_upnp_xml_is_document_complete(void) {
    return 4;
}

int rt_upnp_xml_get_parser_type(void) {
    return 4;
}

int rt_upnp_xml_get_parse_data(void) {
    return 4;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_upnp/src/rt_upnp_xmlparse", rcsid_10CD4C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_upnp/src/rt_upnp_xmlparse", headerfile_rcsid_10CDB0);
