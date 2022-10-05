vector<unsigned int> getrandomarray() 
{
    const unsigned range = 958;
    const unsigned numberToSelect = 958;

    vector< unsigned > remainingNumbers(range);
    vector< unsigned > chosenNumbers(numberToSelect);

    for (unsigned i = 0; i < range; i++)
        remainingNumbers[i] = i;

    for (unsigned i = 0; i < numberToSelect; i++)
    {
        int selectedElement = rand() % (range - i);
        chosenNumbers[i] = remainingNumbers[selectedElement];
        remainingNumbers.erase(remainingNumbers.begin() + selectedElement);
    }

    remainingNumbers.clear();

    return chosenNumbers;
}
