#include <pybind11/pybind11.h>
#include <mijnlib.h>
#include <render.h>

namespace py = pybind11;

/*
PYBIND11_MODULE(mijnlib, m) {
    m.doc() = "pybind11 example plugin"; // Optional module docstring
    m.def("cpp_function", &cppmult, "A function which multiplies two numbers");
}*/

PYBIND11_PLUGIN(mijnlib) {
    py::module m("mijnlib", "pybind11 example plugin");
    //m.def("cpp_function", &cppmult, "A function which multiplies two numbers");
    
    py::class_<Vector2>(m, "vector2")
        .def(py::init<float, float>())
        //.def("x", &Vector2::X)
        //.def("y", &Vector2::Y)
        .def_property("x", &Vector2::X, &Vector2::SetX)
        .def_property("y", &Vector2::Y, &Vector2::SetY)
        .def("copy", &Vector2::Copy, "Copy vector to new instance")
        .def("mag", &Vector2::Mag, "Magnitude of the vector")
        .def("magsq", &Vector2::MagSq, "Squared magnitude of the vector")
        .def("setmag", &Vector2::SetMag, py::return_value_policy::take_ownership, "Set the magnitude of the vector")
        .def("dist", &Vector2::Dist, "Distance of this vector coordinate to another vector coordinate")
        .def("add", static_cast<Vector2* (Vector2::*)(float)>(&Vector2::Add), py::return_value_policy::take_ownership, "Vector-constant addition")
        .def("add", static_cast<Vector2* (Vector2::*)(Vector2)>(&Vector2::Add), py::return_value_policy::take_ownership, "Vector-vector addition")
        .def("sub", static_cast<Vector2* (Vector2::*)(float)>(&Vector2::Sub), py::return_value_policy::take_ownership, "Vector-constant subtraction")
        .def("sub", static_cast<Vector2* (Vector2::*)(Vector2)>(&Vector2::Sub), py::return_value_policy::take_ownership, "Vector-vector subtraction")
        .def("mul", static_cast<Vector2* (Vector2::*)(float)>(&Vector2::Mul), py::return_value_policy::take_ownership, "Vector-constant multiplication")
        .def("mul", static_cast<Vector2* (Vector2::*)(Vector2)>(&Vector2::Mul), py::return_value_policy::take_ownership, "Vector-vector multiplication")
        .def("div", static_cast<Vector2* (Vector2::*)(float)>(&Vector2::Div), py::return_value_policy::take_ownership, "Vector-constant division")
        .def("div", static_cast<Vector2* (Vector2::*)(Vector2)>(&Vector2::Div), py::return_value_policy::take_ownership, "Vector-vector division")
        .def("__repr__",
            [](Vector2 a) {
                return "<vector2(" + std::to_string(a.X()) + ", " + std::to_string(a.Y()) + ")>";
            }
        );

    py::class_<Render>(m, "render")
        .def(py::init<>())
        //.def("draw", &Render::Draw, py::return_value_policy::reference, "Magische functie")
        .def("set_draw_list", &Render::SetDrawList, "iets");

        //.def("cpp_function", &Vector2::cppmult, "A function which multiplies two numbers");
    
    return m.ptr();
}
