<!-- Parent.vue -->
<template>
  <div>
    <Search :toSearchLabel="toSearch" :dataColumn="dataOneColumn" :dataRow="dataOneRow">
      <template v-slot="{ tableColumnAttribute, tableData }">
        <BaseDataList :tableColumnAttribute="tableColumnAttribute" :tableData="tableData"></BaseDataList>
      </template>
    </Search>

    <!-- 插槽必须为 span -->
    <Head :middle="true">
      <span>
        <el-button type="primary">搜索</el-button>
        <el-button type="primary">搜索</el-button>
        <el-button type="primary">搜索</el-button>
      </span>
    </Head>

    <Head>
      <span>
        <el-button type="primary">搜索</el-button>
        <el-button type="primary">搜索</el-button>
        <el-button type="primary">搜索</el-button>
      </span>
    </Head>

    <Head :middle="true"></Head>

    <Head name="自定义标题"></Head>

    <RadioList></RadioList>
  </div>
</template>

<script setup>
import { ref } from 'vue'
import Search from '@/components/search/Search.vue'
import BaseDataList from '@/components/basedatalist/BaseDataList.vue'
import Head from '@/components/head/Head.vue'
import RadioList from '@/components/radio/RadioList.vue'

// 需要搜索的数据传入
// const toSearch = ['单位名称', '信用代码', '联系人', '联系电话']
const toSearch = [
  {
    prop: 'name',
    label: '单位名称',
    input: ''
  },
  {
    prop: 'credit',
    label: '信用代码',
    input: ''
  },
  {
    prop: 'contact',
    label: '联系人',
    input: ''
  },
  {
    prop: 'phone',
    label: '联系电话',
    input: ''
  }
]

// 表格数据 1
// 列属性 attribute
const dataOneColumn = [
  {
    prop: 'name',
    label: '单位名称'
  },
  {
    prop: 'credit',
    label: '信用代码'
  },
  {
    prop: 'examination',
    label: '体检类型'
  },
  {
    prop: 'address',
    label: '所属地区'
  },
  {
    prop: 'category',
    label: '行业类别'
  },
  {
    prop: 'etype',
    label: '经济类型'
  },
  {
    prop: 'scale',
    label: '企业规模'
  },
  {
    prop: 'contact',
    label: '联系人'
  },
  {
    prop: 'phone',
    label: '联系电话'
  }
]
// 每行的数据
const dataOneRow = [
  {
    name: '乐山市峨边盛和矿业',
    credit: '--',
    examination: '健康体检',
    address: '--',
    category: '铁矿采选*',
    etype: '国有企业',
    scale: '--',
    contact: '--',
    phone: '--'
  },
  {
    name: '习水宏旭纸箱有限公司',
    credit: '--',
    examination: '健康体检',
    address: '--',
    category: '--',
    etype: '--',
    scale: '--',
    contact: '蔡徐坤',
    phone: '--'
  },
  {
    name: '四川峨边三丰冶金材料',
    credit: '--',
    examination: '健康体检',
    address: '--',
    category: '--',
    etype: '国有企业',
    scale: '--',
    contact: '--',
    phone: '--'
  }
]
</script>

<style lang="scss" scoped></style>
