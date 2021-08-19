include("window.jl")

myWindow = j3d.Window(800, 600, "JULIA3D")

j3d.Init(myWindow)

while !(j3d.IsClose(myWindow))

    j3d.PollEvent()
    j3d.Clear(myWindow)
    j3d.Display(myWindow)

end

j3d.Destroy(myWindow)