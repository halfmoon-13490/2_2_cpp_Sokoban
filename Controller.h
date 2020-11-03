#include "Model.h"
#include "View.h"
#include "Map.h"
class Controller
{
	Model* _model;
	View* _view;
	Map* _map;
	
public:
	Controller() {
		_model = new Model();
		_view = new View;
		_map = new Map;
	}
	~Controller() {
		delete _model;
		delete _view;
		delete _map;
	}

	void start() {
		_setcursortype(_NOCURSOR);
		_view->start(_model, _map);
	}
};

