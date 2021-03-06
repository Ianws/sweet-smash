/*
TODO: Write class description
*/

#include "game_window.h"

// ------------------------------------------------------------
// Button callback functions
// ------------------------------------------------------------
static void d_button_callback(GtkWidget* widget, gpointer data) {
    char DIRECTION_CHARS[] = {'N', 'W', 'E', 'S'}; // remove this if it can be defined elsewhere
    char dir = DIRECTION_CHARS[(long)data];
    printf("Direction: %c\n", dir);
    gameboard->SwapCandy(dir);
    refresh_window(app);
}

static void c_button_callback(GtkWidget* widget, gpointer data) {
    int idx = (long)data;
    printf("Set selected candy: %d\n", idx);
    gameboard->SetSelectedCandy(idx);
}

// ------------------------------------------------------------
// Assemble the window
// ------------------------------------------------------------
void make_window(GtkApplication* app) {
    GtkWidget* window = (gtk_application_window_new(app));

    gtk_window_set_title(GTK_WINDOW(window), "Candy-Clone");
    gtk_window_set_resizable((GtkWindow*)window, FALSE);
    gtk_window_set_default_size(GTK_WINDOW(window), 500, 500);
}

void fill_window(GtkApplication *app) {
    char remaining_moves[256], points[256], game_over[256];
    int idx;

    sprintf(remaining_moves, "Moves left: %d", gameboard->GetMovesRemaining());
    sprintf(points, "Score: %d", gameboard->GetScore());

    if(gameboard->GetScore() == gameboard->GetMaxScore()) {
        sprintf(game_over, "You win!!");
    } else {
        sprintf(game_over, "You lose :(");
    }

    // declare & initialize window components
    GtkWindow* window = gtk_application_get_active_window(GTK_APPLICATION(app));
    GtkWidget* top_lvl_container = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    GtkWidget* candy_grid = gtk_grid_new();
    GtkWidget* interface_container = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    GtkWidget* move_counter = gtk_label_new(remaining_moves);
    GtkWidget* score = gtk_label_new(points);
    GtkWidget* over = gtk_label_new(game_over);
    GtkWidget* dpad_grid = gtk_grid_new();

    // assemble window components
    gtk_container_add(GTK_CONTAINER(window), top_lvl_container);
    gtk_box_pack_start(GTK_BOX(top_lvl_container), candy_grid, TRUE, TRUE, 0);
    gtk_box_pack_end(GTK_BOX(top_lvl_container), interface_container, FALSE, FALSE, 0);
    if(!gameboard->IsGameOver()) {
        gtk_box_pack_start(GTK_BOX(interface_container), move_counter, FALSE, FALSE, 20);
        gtk_box_pack_start(GTK_BOX(interface_container), score, FALSE, FALSE, 20);
    } else {
        gtk_box_pack_start(GTK_BOX(interface_container), over, FALSE, FALSE, 20);
        gtk_box_pack_start(GTK_BOX(interface_container), move_counter, FALSE, FALSE, 20);
    }
    gtk_box_pack_start(GTK_BOX(interface_container), dpad_grid, FALSE, FALSE, 0);

    idx = gameboard->GetBoardSize() - 1;

    for(int i = 0; i < gameboard->GetRowLength(); i++) {
        for(int j = 0; j < gameboard->GetColLength(); j++) {
            int candy = gameboard->GetCandyColor(idx);
            GtkWidget* currButton = gtk_toggle_button_new();
            GtkWidget* currImage = gtk_image_new_from_file(candy_image_filenames[candy]);
            gtk_button_set_image((GtkButton*)currButton, currImage);
            gtk_grid_attach(GTK_GRID(candy_grid), currButton, j, i, 1, 1);

            // add signal handler to button
            g_signal_connect(currButton, "toggled", G_CALLBACK(c_button_callback),
                             GINT_TO_POINTER(idx));
            idx--;
        }
    }

    // create directional buttons
    for (int i = 1; i < 9; i += 2) { // places buttons in shape of cross
        GtkWidget* currButton = gtk_button_new();
        GtkWidget* currImage = gtk_image_new_from_file(dbutton_image_filenames[i / 2]);
        gtk_button_set_image((GtkButton*)currButton, currImage);
        g_signal_connect(currButton, "clicked", G_CALLBACK(d_button_callback), GINT_TO_POINTER(i / 2));
        gtk_grid_attach(GTK_GRID(dpad_grid), currButton, (i % 3), (i / 3), 1, 1);
    }

    gtk_widget_show_all(GTK_WIDGET(window));

}

void refresh_window(GtkApplication* app) {
    GtkWindow* window = gtk_application_get_active_window(app);
    gtk_widget_destroy(gtk_bin_get_child( GTK_BIN(window) ));
    fill_window(app);
}

static void open(GApplication *app, GFile **files, gint n_files, const gchar *hint) {
    // initialize game board
    if(files != NULL) {
        gameboard = CreateGameModel(g_file_get_path(files[0]));

        make_window(GTK_APPLICATION(app));
        fill_window(GTK_APPLICATION(app));
    }
}

static void activate(GtkApplication *app, gpointer data) {
    printf("usage: ./hw4 path/to/file.json \n");
}

int main(int argc, char **argv) {
    int status;

    app = gtk_application_new("edu.washington.cs", G_APPLICATION_HANDLES_OPEN);
    g_signal_connect(app, "open", G_CALLBACK(open), NULL);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);

    g_object_unref(app);

    if(gameboard != nullptr)
        FreeModel(gameboard);

    return status;
}