
id_counter = 0
ECS = [[]]
components = [[]]
pop!(ECS)
pop!(components)
entities = []



function createEntity()::UInt16
    global id_counter += 1
end


function addComponent(entity, Component)
    if !(entity in entities)
        push!(entities, entity)
        push!(ECS, [])
        push!(components, [])
    end
	
    i = findall(x->x == entity, entities)
    push!(ECS[i[1]], Component)
    push!(components[i[1]], Type{typeof(Component)})
end

function removeComponent(entity, Component)
    if !(entity in entities)
       println("no such an entity!!!") 
    end
	i = findall(x->x == entity, entities)
	if !(Component in components[i[1]])
		println("entity $(entity) does not contain this component!!!")
	end
	c = findall(x->x == Component, components[i[1]])
    deleteat!(ECS[i[1]], c[1])
	deleteat!(components[i[1]], c[1])
end

function getComponent(entity, Component)
    i = findall(x->x == entity, entities)
	if !(Component in components[i[1]])
		println("entity $(entity) does not contain this component!!!")
		return nothing
	end
	
    c = findall(x->x == Component, components[i[1]])
    return ECS[i[1]][c[1]]
end

# COMPONENTS
struct Transform
    x::Float32
    y::Float32
    z::Float32

end

struct SpriteRenderer
    
end

#ecs = EntityComponentSystem()

e1 = createEntity()
e2 = createEntity()
e3 = createEntity()

println(e1)
println(e2)
println(e3)


addComponent(e2, SpriteRenderer())
println(ECS)

addComponent(e3, Transform(0, 0, 0))
println(ECS)

addComponent(e1, Transform(5, 46, 8))
println(ECS)
addComponent(e1, SpriteRenderer())
println(ECS)

addComponent(e2, Transform(0, 1453, 5))
println(ECS)


removeComponent(e2, Type{Transform})
println(ECS)

