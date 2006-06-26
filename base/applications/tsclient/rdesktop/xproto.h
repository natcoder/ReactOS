void xclip_handle_SelectionNotify(RDPCLIENT * This, XSelectionEvent * event);
void xclip_handle_SelectionRequest(RDPCLIENT * This, XSelectionRequestEvent * xevent);
void xclip_handle_SelectionClear(RDPCLIENT * This);
void xclip_handle_PropertyNotify(RDPCLIENT * This, XPropertyEvent * xev);
int ewmh_get_window_state(RDPCLIENT * This, Window w);
int ewmh_change_state(RDPCLIENT * This, Window wnd, int state);
int ewmh_move_to_desktop(RDPCLIENT * This, Window wnd, unsigned int desktop);
int ewmh_get_window_desktop(RDPCLIENT * This, Window wnd);
void ewmh_set_wm_name(RDPCLIENT * This, Window wnd, const char *title);
int ewmh_set_window_popup(RDPCLIENT * This, Window wnd);
int ewmh_set_window_modal(RDPCLIENT * This, Window wnd);
