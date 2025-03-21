#ifndef ERRORS_H
#define ERRORS_H

void fix_error_init(fix_error_t* err);
void fix_error_fini(fix_error_t* err);
void fix_error_set(fix_error_t* err, const Exception& e);

#endif // ERRORS_H