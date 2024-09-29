#include "aloo.h"
#include "common/app.h"

AlooWidget *labelGrid;
AlooWidget *navbar;
AlooWidget *navMenu;
AlooWidget *nothingLabel = 0;
AlooWidget *tabs;
AlooWidget *input;
struct _logger *lg;
int isNothing = 1;

struct _labelList {
	AlooWidget *labels[10];
	int len;
} labelList;

void changeView() {
	char **classes = CSS.getClasses(tabs);
	if (!strcmp(classes[0], "")) {
		classes[0] = "switch";
	} else {
		classes[0] = "";
	}
	CSS.setClasses(tabs, classes);
}

static void toggleNav() {
	char **classes = CSS.getClasses(navbar);
	lg->log(lg, "Toggled Nav, %s", classes[0]);

	if (!strcmp(classes[0], "vertical")) {
		CSS.removeClass(navMenu, "nav-menu-show");
		CSS.addClass(navMenu, "nav-menu-hidden");
		classes[0] = "horizontal";
	} else {
		CSS.removeClass(navMenu, "nav-menu-hidden");
		CSS.addClass(navMenu, "nav-menu-show");
		classes[0] = "vertical";
	}
	CSS.setClasses(navbar, classes);
}

void nothingHappened(AlooWidget *data);

void print_hello() {
	if (labelList.len == 9) {
		nothingLabel = Label.new("Maximum number of labels reached");
		Widget.set.name(nothingLabel, "no-label");
		isNothing = 1;
		Grid.attach(labelGrid, nothingLabel, 1, 4, 3, 1);
		return;
	}

	if (strlen(Input.get.value(input)) == 0) return;
	if (isNothing && nothingLabel != 0) nothingHappened(labelGrid);
	AlooWidget *label = Label.new(Input.get.value(input));
	Widget.set.name(label, "label");
	Grid.attach(labelGrid, label, (labelList.len / 3) + 1,
				(labelList.len % 3) + 1, 1, 1);
	labelList.labels[labelList.len] = label;
	labelList.len++;
}
void removeLabel() {
	if (labelList.len == 9) {
		Grid.remove(labelGrid, nothingLabel);
		nothingLabel = 0;
		isNothing = 0;
	}
	if (isNothing && nothingLabel != 0) return;
	if (labelList.len == 0) {
		isNothing = 0;
		nothingHappened(labelGrid);
		return;
	}
	Grid.remove(labelGrid, labelList.labels[labelList.len - 1]);
	AlooWidget *label = labelList.labels[labelList.len - 1];
	labelList.len--;
}
void nothingHappened(AlooWidget *data) {
	if (isNothing) {
		Grid.remove(data, nothingLabel);
		nothingLabel = 0;
		isNothing = 0;
	} else {
		nothingLabel = Label.new("Nothing Happened");
		Widget.set.name(nothingLabel, "no-label");
		Grid.attach(data, nothingLabel, 1, 1, 2, 1);
		isNothing = 1;
	}
}

static void activate(gpointer data) {
	AlooApplication *app = malloc(sizeof(AlooApplication));
	app->app = data;
	int x = 1912, y = 992;
	labelList.len = 0;
	AlooBuilder *builder = Builder.create();
	Builder.addFile(builder, "builder.ui", NULL);
	AlooWidget *appBody = Builder.alooFromBuilder(builder, "app");
	AlooWidget *box = Builder.alooFromBuilder(builder, "box");
	tabs = Builder.alooFromBuilder(builder, "tabs");
	AlooWidget *window = Builder.alooFromBuilder(builder, "gtk-window");
	AlooWidget *buttonWidget = Builder.alooFromBuilder(builder, "add");
	AlooWidget *rmLabelWidget = Builder.alooFromBuilder(builder, "remove");
	AlooWidget *grid = Builder.alooFromBuilder(builder, "button-grid");
	navbar = Builder.alooFromBuilder(builder, "navbar");
	input = Builder.alooFromBuilder(builder, "label-name");
	AlooWidget *menuBar = Builder.alooFromBuilder(builder, "menu-bar");
	AlooWidget *boxBody = Builder.alooFromBuilder(builder, "box-body");

	Widget.set.orientation(box, GTK_ORIENTATION_VERTICAL);
	Widget.set.orientation(navbar, GTK_ORIENTATION_VERTICAL);
	Widget.set.orientation(appBody, GTK_ORIENTATION_VERTICAL);
	Widget.set.orientation(boxBody, GTK_ORIENTATION_HORIZONTAL);
	Widget.set.orientation(tabs, GTK_ORIENTATION_HORIZONTAL);
	CSS.setSize(buttonWidget, 100, 50);
	CSS.setSize(rmLabelWidget, 125, 50);

	Button.set.label(buttonWidget, "add");
	Button.set.label(rmLabelWidget, "remove");

	Window.set.size(window, x, y);
	Window.set.AppWindow(window, app);
	Widget.addEventListener(buttonWidget, "clicked", print_hello, NULL);
	Widget.addEventListener(rmLabelWidget, "clicked", removeLabel, NULL);

	labelGrid = Grid.new();
	Widget.set.name(labelGrid, "label-grid");
	Widget.set.horizontalAlign(
		Widget.set.verticalAlign(labelGrid, GTK_ALIGN_CENTER),
		GTK_ALIGN_CENTER);
	Widget.set.horizontalAlign(Widget.set.verticalAlign(box, GTK_ALIGN_CENTER),
							   GTK_ALIGN_CENTER);
	Box.append(box, labelGrid);

	Widget.set.horizontalAlign(Widget.set.verticalAlign(grid, GTK_ALIGN_CENTER),
							   GTK_ALIGN_CENTER);

	CSS.importPath("style.css");

	Grid.column_spacing(grid, 20);
	Grid.row_spacing(labelGrid, 5);
	Grid.column_spacing(labelGrid, 5);

	CSS.setWidth(Builder.alooFromBuilder(builder, "nav-show"), x);
	CSS.setWidth(box, x);
	CSS.setHeight(box, y);

	Widget.addEventListener(menuBar, "clicked", toggleNav, NULL);
	Widget.addEventListener(Widget.alooFromBuilder(builder, "view"), "clicked",
							changeView, NULL);

	navMenu = Grid.new();
	Widget.set.name(navMenu, "nav-menu");
	const char *menus[] = {"File", "Edit", "Save"};
	for (int i = 0; i < 3; i++) {
		AlooWidget *label = Button.newWithLabel(menus[i]);
		Widget.set.name(label, "menu-opt");
		CSS.setSize(label, 100, 20);
		Grid.attach(navMenu, label, 0, i, 1, 1);
	}
	CSS.setSize(box, x, y);
	CSS.setSize(navMenu, 100, y);
	CSS.addClass(navMenu, "nav-menu-show");

	AlooWidget *navShow = Builder.alooFromBuilder(builder, "nav-show");
	CSS.setSize(navShow, x, 70);
	char **classes = CSS.getClasses(navMenu);
	for (int i = 0; i < sizeof(classes) / sizeof(classes[0]); i++) {
		printf("%s\n", classes[i]);
	}

	Box.prepend(boxBody, navMenu);

	Window.show(window);
	Builder.unref(builder);
}

int main(int argc, char **argv) {
	lg = newLogger();
	struct AlooAppOptions opts = getAppFlags.none(argc, argv);
	AlooApplication *app = Application.create("com.aloo-use.aloo-edit", opts);
	Application.add_event_listener(app, "activate", activate, app->app);
	int status = Application.run(app);
	Application.unref(app);
	return status;
}
