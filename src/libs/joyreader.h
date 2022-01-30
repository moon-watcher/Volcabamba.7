#pragma once

typedef struct
{
    unsigned port:1;
    unsigned changed;
    unsigned active;
}
Joyreader;


void joyreader_init   ( Joyreader *joy, unsigned port );
void joyreader_update ( Joyreader *joy );
void joyreader_reset  ( Joyreader *joy );


#define joy_active(JOY)                 ( JOY->active )
#define joy_active_up(JOY)            ( ( joy_active(JOY)   >>  0 ) & 1 )
#define joy_active_down(JOY)          ( ( joy_active(JOY)   >>  1 ) & 1 )
#define joy_active_left(JOY)          ( ( joy_active(JOY)   >>  2 ) & 1 )
#define joy_active_right(JOY)         ( ( joy_active(JOY)   >>  3 ) & 1 )
#define joy_active_a(JOY)             ( ( joy_active(JOY)   >>  6 ) & 1 )
#define joy_active_b(JOY)             ( ( joy_active(JOY)   >>  4 ) & 1 )
#define joy_active_c(JOY)             ( ( joy_active(JOY)   >>  5 ) & 1 )
#define joy_active_x(JOY)             ( ( joy_active(JOY)   >> 10 ) & 1 )
#define joy_active_y(JOY)             ( ( joy_active(JOY)   >>  9 ) & 1 )
#define joy_active_z(JOY)             ( ( joy_active(JOY)   >>  8 ) & 1 )
#define joy_active_start(JOY)         ( ( joy_active(JOY)   >>  7 ) & 1 )
#define joy_active_mode(JOY)          ( ( joy_active(JOY)   >> 11 ) & 1 )
#define joy_active_vertical(JOY)        ( joy_active_up(JOY)         | joy_active_down(JOY) )
#define joy_active_horizontal(JOY)      ( joy_active_left(JOY)       | joy_active_right(JOY) )
#define joy_active_dir(JOY)             ( joy_active_vertical(JOY)   | joy_active_horizontal(JOY) )
#define joy_active_abc(JOY)             ( joy_active_a(JOY)          | joy_active_b(JOY)   | joy_active_c(JOY) )
#define joy_active_xyz(JOY)             ( joy_active_x(JOY)          | joy_active_y(JOY)   | joy_active_z(JOY) )
#define joy_active_btn(JOY)             ( joy_active_abc(JOY)        | joy_active_xyz(JOY) )

#define joy_changed(JOY)                ( JOY->changed )
#define joy_changed_up(JOY)           ( ( joy_changed(JOY)  >>  0 ) & 1 )
#define joy_changed_down(JOY)         ( ( joy_changed(JOY)  >>  1 ) & 1 )
#define joy_changed_left(JOY)         ( ( joy_changed(JOY)  >>  2 ) & 1 )
#define joy_changed_right(JOY)        ( ( joy_changed(JOY)  >>  3 ) & 1 )
#define joy_changed_a(JOY)            ( ( joy_changed(JOY)  >>  6 ) & 1 )
#define joy_changed_b(JOY)            ( ( joy_changed(JOY)  >>  4 ) & 1 )
#define joy_changed_c(JOY)            ( ( joy_changed(JOY)  >>  5 ) & 1 )
#define joy_changed_x(JOY)            ( ( joy_changed(JOY)  >> 10 ) & 1 )
#define joy_changed_y(JOY)            ( ( joy_changed(JOY)  >>  9 ) & 1 )
#define joy_changed_z(JOY)            ( ( joy_changed(JOY)  >>  8 ) & 1 )
#define joy_changed_start(JOY)        ( ( joy_changed(JOY)  >>  7 ) & 1 )
#define joy_changed_mode(JOY)         ( ( joy_changed(JOY)  >> 11 ) & 1 )
#define joy_changed_vertical(JOY)       ( joy_changed_up(JOY)        | joy_changed_down(JOY) )
#define joy_changed_horizontal(JOY)     ( joy_changed_left(JOY)      | joy_changed_right(JOY) )
#define joy_changed_dir(JOY)            ( joy_changed_vertical(JOY)  | joy_changed_horizontal(JOY) )
#define joy_changed_abc(JOY)            ( joy_changed_a(JOY)         | joy_changed_b(JOY)  | joy_changed_c(JOY) )
#define joy_changed_xyz(JOY)            ( joy_changed_x(JOY)         | joy_changed_y(JOY)  | joy_changed_z(JOY) )
#define joy_changed_btn(JOY)            ( joy_changed_abc(JOY)       | joy_changed_xyz(JOY) )

#define joy_inactive(JOY)               ( ~joy_active(JOY) )
#define joy_inactive_up(JOY)          ( ( joy_inactive(JOY) >>  0 ) & 1 )
#define joy_inactive_down(JOY)        ( ( joy_inactive(JOY) >>  1 ) & 1 )
#define joy_inactive_left(JOY)        ( ( joy_inactive(JOY) >>  2 ) & 1 )
#define joy_inactive_right(JOY)       ( ( joy_inactive(JOY) >>  3 ) & 1 )
#define joy_inactive_a(JOY)           ( ( joy_inactive(JOY) >>  6 ) & 1 )
#define joy_inactive_b(JOY)           ( ( joy_inactive(JOY) >>  4 ) & 1 )
#define joy_inactive_c(JOY)           ( ( joy_inactive(JOY) >>  5 ) & 1 )
#define joy_inactive_x(JOY)           ( ( joy_inactive(JOY) >> 10 ) & 1 )
#define joy_inactive_y(JOY)           ( ( joy_inactive(JOY) >>  9 ) & 1 )
#define joy_inactive_z(JOY)           ( ( joy_inactive(JOY) >>  8 ) & 1 )
#define joy_inactive_start(JOY)       ( ( joy_inactive(JOY) >>  7 ) & 1 )
#define joy_inactive_mode(JOY)        ( ( joy_inactive(JOY) >> 11 ) & 1 )
#define joy_inactive_vertical(JOY)      ( joy_inactive_up(JOY)       | joy_inactive_down(JOY) )
#define joy_inactive_horizontal(JOY)    ( joy_inactive_left(JOY)     | joy_inactive_right(JOY) )
#define joy_inactive_dir(JOY)           ( joy_inactive_vertical(JOY) | joy_inactive_horizontal(JOY) )
#define joy_inactive_abc(JOY)           ( joy_inactive_a(JOY)        | joy_inactive_b(JOY) | joy_inactive_c(JOY) )
#define joy_inactive_xyz(JOY)           ( joy_inactive_x(JOY)        | joy_inactive_y(JOY) | joy_inactive_z(JOY) )
#define joy_inactive_btn(JOY)           ( joy_inactive_abc(JOY)      | joy_inactive_xyz(JOY) )

#define joy_pressed(JOY)                ( joy_active(JOY)  & joy_changed(JOY) )
#define joy_pressed_up(JOY)           ( ( joy_pressed(JOY)  >>  0 ) & 1 )
#define joy_pressed_down(JOY)         ( ( joy_pressed(JOY)  >>  1 ) & 1 )
#define joy_pressed_left(JOY)         ( ( joy_pressed(JOY)  >>  2 ) & 1 )
#define joy_pressed_right(JOY)        ( ( joy_pressed(JOY)  >>  3 ) & 1 )
#define joy_pressed_a(JOY)            ( ( joy_pressed(JOY)  >>  6 ) & 1 )
#define joy_pressed_b(JOY)            ( ( joy_pressed(JOY)  >>  4 ) & 1 )
#define joy_pressed_c(JOY)            ( ( joy_pressed(JOY)  >>  5 ) & 1 )
#define joy_pressed_x(JOY)            ( ( joy_pressed(JOY)  >> 10 ) & 1 )
#define joy_pressed_y(JOY)            ( ( joy_pressed(JOY)  >>  9 ) & 1 )
#define joy_pressed_z(JOY)            ( ( joy_pressed(JOY)  >>  8 ) & 1 )
#define joy_pressed_start(JOY)        ( ( joy_pressed(JOY)  >>  7 ) & 1 )
#define joy_pressed_mode(JOY)         ( ( joy_pressed(JOY)  >> 11 ) & 1 )
#define joy_pressed_vertical(JOY)       ( joy_pressed_up(JOY)        | joy_pressed_down(JOY) )
#define joy_pressed_horizontal(JOY)     ( joy_pressed_left(JOY)      | joy_pressed_right(JOY) )
#define joy_pressed_dir(JOY)            ( joy_pressed_vertical(JOY)  | joy_pressed_horizontal(JOY) )
#define joy_pressed_abc(JOY)            ( joy_pressed_a(JOY)         | joy_pressed_b(JOY)  | joy_pressed_c(JOY) )
#define joy_pressed_xyz(JOY)            ( joy_pressed_x(JOY)         | joy_pressed_y(JOY)  | joy_pressed_z(JOY) )
#define joy_pressed_btn(JOY)            ( joy_pressed_abc(JOY)       | joy_pressed_xyz(JOY) )

#define joy_released(JOY)               ( ~joy_active(JOY) & joy_changed(JOY) )
#define joy_released_up(JOY)          ( ( joy_released(JOY) >>  0 ) & 1 )
#define joy_released_down(JOY)        ( ( joy_released(JOY) >>  1 ) & 1 )
#define joy_released_left(JOY)        ( ( joy_released(JOY) >>  2 ) & 1 )
#define joy_released_right(JOY)       ( ( joy_released(JOY) >>  3 ) & 1 )
#define joy_released_a(JOY)           ( ( joy_released(JOY) >>  6 ) & 1 )
#define joy_released_b(JOY)           ( ( joy_released(JOY) >>  4 ) & 1 )
#define joy_released_c(JOY)           ( ( joy_released(JOY) >>  5 ) & 1 )
#define joy_released_x(JOY)           ( ( joy_released(JOY) >> 10 ) & 1 )
#define joy_released_y(JOY)           ( ( joy_released(JOY) >>  9 ) & 1 )
#define joy_released_z(JOY)           ( ( joy_released(JOY) >>  8 ) & 1 )
#define joy_released_start(JOY)       ( ( joy_released(JOY) >>  7 ) & 1 )
#define joy_released_mode(JOY)        ( ( joy_released(JOY) >> 11 ) & 1 )
#define joy_released_vertical(JOY)      ( joy_released_up(JOY)       | joy_released_down(JOY) )
#define joy_released_horizontal(JOY)    ( joy_released_left(JOY)     | joy_released_right(JOY) )
#define joy_released_dir(JOY)           ( joy_released_vertical(JOY) | joy_released_horizontal(JOY) )
#define joy_released_abc(JOY)           ( joy_released_a(JOY)        | joy_released_b(JOY) | joy_released_c(JOY) )
#define joy_released_xyz(JOY)           ( joy_released_x(JOY)        | joy_released_y(JOY) | joy_released_z(JOY) )
#define joy_released_btn(JOY)           ( joy_released_abc(JOY)      | joy_released_xyz(JOY) )



/*
#define EVAL(ACTION,A)  ( ( j->ACTION >> A ) & 1 )

#define JOYDEFINE(ACTION) \
    unsigned joy_##ACTION              ( Joyreader *j ) { return j->ACTION; } \
    \
    unsigned joy_##ACTION##_up         ( Joyreader *j ) { return EVAL(ACTION,0); } \
    unsigned joy_##ACTION##_down       ( Joyreader *j ) { return EVAL(ACTION,1); } \
    unsigned joy_##ACTION##_left       ( Joyreader *j ) { return EVAL(ACTION,2); } \
    unsigned joy_##ACTION##_right      ( Joyreader *j ) { return EVAL(ACTION,3); } \
    unsigned joy_##ACTION##_a          ( Joyreader *j ) { return EVAL(ACTION,6); } \
    unsigned joy_##ACTION##_b          ( Joyreader *j ) { return EVAL(ACTION,4); } \
    unsigned joy_##ACTION##_c          ( Joyreader *j ) { return EVAL(ACTION,5); } \
    unsigned joy_##ACTION##_x          ( Joyreader *j ) { return EVAL(ACTION,10); } \
    unsigned joy_##ACTION##_y          ( Joyreader *j ) { return EVAL(ACTION,9); } \
    unsigned joy_##ACTION##_z          ( Joyreader *j ) { return EVAL(ACTION,8); } \
    unsigned joy_##ACTION##_start      ( Joyreader *j ) { return EVAL(ACTION,7); } \
    unsigned joy_##ACTION##_mode       ( Joyreader *j ) { return EVAL(ACTION,11); } \
    \
    unsigned joy_##ACTION##_vertical   ( Joyreader *j ) { return EVAL(ACTION,0) | EVAL(ACTION,1); } \
    unsigned joy_##ACTION##_horizontal ( Joyreader *j ) { return EVAL(ACTION,2) | EVAL(ACTION,3); } \
    unsigned joy_##ACTION##_dir        ( Joyreader *j ) { return EVAL(ACTION,0) | EVAL(ACTION,1) | EVAL(ACTION,2) | EVAL(ACTION,3); } \
    unsigned joy_##ACTION##_abc        ( Joyreader *j ) { return EVAL(ACTION,4) | EVAL(ACTION,5) | EVAL(ACTION,6); } \
    unsigned joy_##ACTION##_xyz        ( Joyreader *j ) { return EVAL(ACTION,8) | EVAL(ACTION,9) | EVAL(ACTION,10); } \
    unsigned joy_##ACTION##_btn        ( Joyreader *j ) { return EVAL(ACTION,4) | EVAL(ACTION,5) | EVAL(ACTION,6) | EVAL(ACTION,8) | EVAL(ACTION,9) | EVAL(ACTION,10); }


JOYDEFINE ( active   );
JOYDEFINE ( changed  );
JOYDEFINE ( inactive );
JOYDEFINE ( pressed  );
JOYDEFINE ( released );
*/