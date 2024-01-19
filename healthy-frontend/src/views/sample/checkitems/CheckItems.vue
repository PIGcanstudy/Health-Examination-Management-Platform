<template>
  <div>
    <CheckItems :tcProject="tableDataForTc" :cytaocan="tableDataForCy" :selectDown="selectDown" />
  </div>
</template>

<script setup>
import CheckItems from '@/components/checkitems/CheckItems.vue'


//套餐项目-表格数据
const tableDataForTc = [
  {
    name: '项目1',
    salePrice: '10',
  },
  {
    name: '项目2',
    salePrice: '20',
  },
  {
    name: '项目3',
    salePrice: '30',
  },
  {
    
    name: '项目4',
    salePrice: '40',
  },
  {
    name: '项目5',
    salePrice: '50',
  },
  {
    name: '项目6',
    salePrice: '60',
  },
  {
    name: '项目7',
    salePrice: '70',
  },
  {
    
    name: '项目8',
    salePrice: '80',
  },
  {
    name: '项目9',
    salePrice: '90',
  },
  {
    name: '项目10',
    salePrice: '100',
  },
  {
    name: '项目11',
    salePrice: '110',
  },
  {
    
    name: '项目12',
    salePrice: '120',
  },
]

  //从业套餐-表格数据
const tableDataForCy = [
  {
    tcmc: '优惠套餐1',
    tcjp: 'YHTC',
  },
  {
    tcmc: '健康套餐1',
    tcjp: 'CYTJ',
  },
  {
    tcmc: '优惠套餐2',
    tcjp: 'JC3',
  },
  {
    tcmc: '健康套餐2',
    tcjp: 'JC4',
  },
]

  // 下拉菜单存放数据区域
const selectDown = [
  {
    value: 'Option',
    label: '蔡徐坤'},
    {
    value: 'Option1',
    label: '蔡徐坤1'
    },
    {
    value: 'Option2',
    label: '蔡徐坤2'
    },
    {value: 'Option3',
    label: '蔡徐坤3',
  },
  {
    value: 'Option4',
    label: '蔡徐坤4'},
    {
    value: 'Option5',
    label: '蔡徐坤5'
    },
    {
    value: 'Option6',
    label: '蔡徐坤6'
    },
    {value: 'Option7',
    label: '蔡徐坤7',
  },
   {
    value: 'Option8',
    label: '蔡徐坤8'},
    {
    value: 'Option9',
    label: '蔡徐坤9'
    },
    {
    value: 'Option10',
    label: '蔡徐坤10'
    },
    {value: 'Option11',
    label: '蔡徐坤11',
  }
]
</script>

<style lang="scss" scoped></style>
