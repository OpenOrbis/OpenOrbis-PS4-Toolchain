package main

import (
	"debug/elf"
	"encoding/binary"
	"errors"
)

////
// OrbisELF specific helper functions
////

// OrbisElf.getFileOffsetsBySectionName searches the section header table of the input ELF with the given name and
// returns that section's offset as well as error. If the section name does not exist, an offset of 0 and an error is
// returned. The offset and nil are returned otherwise.
func (orbisElf *OrbisElf) getFileOffsetBySectionName(name string) (int64, error) {
	section := orbisElf.ElfToConvert.Section(name)

	if section != nil {
		return int64(orbisElf.ElfToConvert.Section(name).Offset), nil
	}

	return 0, errors.New("tried to access a non-existent section")
}

// OrbisElf.getDynamicTag searches the dynamic table of the input ELF with the given tag and returns that tag's value as
// well as error. If the tag does not exist, or if the dynamic table cannot be found, a value of 0 and an error is returned.
// The value and nil are returned otherwise.
func (orbisElf *OrbisElf) getDynamicTag(tag elf.DynTag) (uint64, error) {
	// Get the dynamic table data
	dynamicTableSegment := orbisElf.ElfToConvert.SectionByType(elf.SHT_DYNAMIC)

	if dynamicTableSegment == nil {
		return 0, nil
	}

	dynamicTableData, err := dynamicTableSegment.Data()

	if err != nil {
		return 0, err
	}

	// We'll move dynamicTableData as a pointer each time we read an entry - thus this loop will terminate when we run
	// out of data
	for len(dynamicTableData) > 0 {
		t := elf.DynTag(orbisElf.ElfToConvert.ByteOrder.Uint64(dynamicTableData[0x0:0x8]))
		v := orbisElf.ElfToConvert.ByteOrder.Uint64(dynamicTableData[0x8:0x10])

		dynamicTableData = dynamicTableData[0x10:]

		if t == tag {
			return v, nil
		}
	}

	return 0, nil
}

// OrbisElf.getSymbol searches the symbol table of the input ELF with the given name and returns the corresponding elf.Symbol
// object. If the symbol does not exist, an empty elf.Symbol object is returned.
func (orbisElf *OrbisElf) getSymbol(name string) elf.Symbol {
	symbols, _ := orbisElf.ElfToConvert.Symbols()

	for _, symbol := range symbols {
		if symbol.Name == name {
			return symbol
		}
	}

	return elf.Symbol{}
}

// OrbisElf.getProgramHeader searches the program header table of the input ELF with the given type and flags, and returns
// a pointer to that program header if it's found. If it cannot be found, a nil pointer is returned.
func (orbisElf *OrbisElf) getProgramHeader(headerType elf.ProgType, headerFlags elf.ProgFlag) *elf.Prog {
	for _, header := range orbisElf.ElfToConvert.Progs {
		if header.Type == headerType && header.Flags == headerFlags {
			return header
		}
	}

	return nil
}

// checkIfLibraryContainsSymbol takes a given library and symbol name, and checks if the library contains that symbol. It
// returns a boolean of whether or not that library contains that symbol, as well as error. If we cannot get a libraries
// symbol list, false and an error is returned. Otherwise, the true or false and nil are returned.
func checkIfLibraryContainsSymbol(librarySymbols []elf.Symbol, symbolName string) bool {
	for _, symbol := range librarySymbols {
		if symbol.Name == symbolName {
			return true
		}
	}

	return false
}

// intToByteArray takes a given integer and writes it into a byte array (little endian) and returns it.
func intToByteArray(value int) []byte {
	valueBuff := make([]byte, 4)
	binary.LittleEndian.PutUint32(valueBuff, uint32(value))

	return valueBuff
}

// writeNullBytes takes a given size and writes null bytes to the buffer. Returns the number of null bytes written.
func writeNullBytes(buffer *[]byte, size uint64) uint64 {
	nullBytes := make([]byte, size)

	for i := uint64(0); i < size; i++ {
		nullBytes[i] = 0
	}

	*buffer = append(*buffer, nullBytes...)
	return size
}

// writePaddingBytes takes a given size and alignment, and uses that to write null padding to buffer. Returns the number of
// null bytes written.
func writePaddingBytes(buffer *[]byte, size uint64, align uint64) uint64 {
	padding := -size & (align - 1)
	return writeNullBytes(buffer, padding)
}

// contains takes a given slice and element, and checks if the element is present within the slice. Returns true if it is
// present, false otherwise.
func contains(slice []string, element string) bool {
	for _, v := range slice {
		if v == element {
			return true
		}
	}

	return false
}

////
// OrderedMap specific types and functions
////

// Type OrderedMap is a type that contains a map as well as a key list. This will ensure the map maintains order, as normal
// hash maps do not guarantee order, which can produce hard to track down bugs later.
type OrderedMap struct {
	keys   []interface{}
	values map[interface{}]interface{}
}

// NewOrderedMap creates a new OrderedMap structure and returns it.
func NewOrderedMap() *OrderedMap {
	orderedMap := OrderedMap{}
	orderedMap.keys = []interface{}{}
	orderedMap.values = map[interface{}]interface{}{}
	return &orderedMap
}

// OrderedMap.Get uses a given key to return the corresponding mapping.
func (orderedMap *OrderedMap) Get(key interface{}) interface{} {
	val, _ := orderedMap.values[key]
	return val
}

// OrderedMap.Set uses a given key to set that key's mapping to a given value.
func (orderedMap *OrderedMap) Set(key interface{}, value interface{}) {
	_, exists := orderedMap.values[key]

	if !exists {
		orderedMap.keys = append(orderedMap.keys, key)
	}

	orderedMap.values[key] = value
}

// OrderedMap.Keys returns the current list of keys for the OrderedMap.
func (orderedMap *OrderedMap) Keys() []interface{} {
	return orderedMap.keys
}
