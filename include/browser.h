typedef enum {
    BROWSER_UNKNOWN,
    BROWSER_OK,
    BROWSER_BADARG,
    BROWSER_ERROR
} browser_error_t;

typedef void (*browser_cb)(const char *);

typedef struct {
    char * path;
    browser_cb cb;
} browser_settings_t;


browser_error_t browser_init(const browser_settings_t * settings);
browser_error_t browser_fini(void);
browser_error_t browser_next(void);
