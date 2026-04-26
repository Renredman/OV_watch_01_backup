#ifndef OV_PAGE_ROUTER_H
#define OV_PAGE_ROUTER_H

#include <stdbool.h>

#include "Types/PageType.h"

bool PageRouter_BuildBackNavigation(lv_ui *ui, lv_obj_t *current_scr, PageMessage *message);
void PageRouter_Apply(lv_ui *ui, const PageMessage *message);

#endif /* OV_PAGE_ROUTER_H */
