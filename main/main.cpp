#include "../view/view.h"
#include "../model/iplAnalyser.h"
#include "../controller/iplController.h"

int main() {
    Display view;
    IplAnalyser analyser;
    IplController controller(view, analyser);
    controller.showOptions();
    
    return 0;
}