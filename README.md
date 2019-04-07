# heap куча

## Сборка проекта

	make


## Удаление

	make clean

## Пример

	
	Heap<int> hp;

	hp.push_back(6);
	hp.push_back(9);
	hp.push_back(8);

	hp.push_back(10);
	hp.push_back(3);
	hp.push_back(4);
	hp.push_back(1);
	hp.push_back(5);
	hp.push_back(16);
	hp.push_back(11);
	hp.push_back(5);

	  

	for (auto it = hp.cbegin(); it != hp.cend(); ++it ) {
		std::cout << *it << " ";
	}
    std::cout << std::endl;
    

    std::vector<int> v(11);

    std::copy( hp.cbegin(), hp.cend(), v.begin() );

	for (auto it = v.cbegin(); it != v.cend(); ++it ) {
		std::cout << *it << " ";
	}
    std::cout << std::endl;


	printf("Ok\n");

