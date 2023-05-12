    def variable_length(**kwargs)
        print(f"{len(kwargs)}data structures and their operations:")
        for title, name in kwargs.itmes():
            print(f"\t{title}->{name}")

    variable_length(stack=" pop, push", queue="enqueue, dequeue", list="add, delete")