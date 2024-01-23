<!-- 团检单位 -->
<template>
  <div class="contain">
    <BaseDataList
      :use-form="useForm"
      :form-data="formData"
      :table-data="tableData"
      :table-column-attribute="tableColumnAttribute"
      :total="total"
      :use-pagination="usePagination"
      :pagination-data="paginationData"
      :handle-edit="handleEdit"
      @update-table-data="handlePageChange"
      @update-selected-rows="selectRows"
    >
      <!-- form表单区域 -->
      <template #form>
        <el-form-item label="单位名称">
          <el-input v-model="formData.unitName"></el-input>
        </el-form-item>
        <el-form-item label="信用代码">
          <el-input v-model="formData.creditCode"></el-input>
        </el-form-item>
        <el-form-item label="联系人">
          <el-input v-model="formData.contactPerson"></el-input>
        </el-form-item>
        <el-form-item label="联系电话">
          <el-input v-model="formData.contactPhone"></el-input>
        </el-form-item>
        <el-form-item>
          <el-button type="primary">搜索</el-button>
        </el-form-item>
        <el-form-item>
          <el-button>重置</el-button>
        </el-form-item>
      </template>

      <!-- operation功能区域 -->
      <template #operation>
        <div class="operation">
          <el-button type="primary" style="margin-right: 10px">新增</el-button>
          <el-select v-model="selectValue" placeholder="更多操作" style="width: 100px; margin-right: 10px"></el-select>
          <el-button @click="closeForm">关闭搜索</el-button>
          <el-button @click="closeHint">关闭提示</el-button>
        </div>
      </template>

      <!-- 多选清除栏 -->
      <template #hint>
        <div v-if="useHint" class="hint">
          <span> (!) 已选择{{ selectedTotal }}项</span>
          <el-button type="primary" link style="margin-bottom: 3px">清空</el-button>
        </div>
      </template>
    </BaseDataList>
  </div>
</template>

<script setup>
import { ref, reactive } from 'vue'
import BaseDataList from '@/components/basedatalist/BaseDataList.vue'
const selectValue = ref('')
const useHint = ref('true')
const useForm = ref('true')
const usePagination = ref('true')
// table列
const tableColumnAttribute = ref([
  { prop: 'name', label: '单位名称', width: '240', align: 'center' },
  { prop: 'credit', label: '信用代码', width: '120', align: 'center' },
  { prop: 'examination', label: '体检类型', width: '120', align: 'center' },
  { prop: 'address', label: '所属地区', width: '120', align: 'center' },
  { prop: 'category', label: '行业类别', width: '120', align: 'center' },
  { prop: 'etype', label: '经济类型', width: '120', align: 'center' },
  { prop: 'scale', label: '企业规模', width: '120', align: 'center' },
  { prop: 'contact', label: '联系人', width: '120', align: 'center' },
  { prop: 'phone', label: '联系电话', width: '120', align: 'center' }
])
// table数据
const tableData = ref([
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
    name: '---',
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
    name: '乐山市峨边盛和矿业',
    credit: '--',
    examination: '健康体检',
    address: '--',
    category: '铁矿采选*',
    etype: '国有企业',
    scale: '--',
    contact: '--',
    phone: '--'
  }
])
const formData = reactive({
  unitName: '',
  creditCode: '',
  contactPerson: '',
  contactPhone: ''
})
const closeForm = () => {
  useForm.value = !useForm.value
}
const closeHint = () => {
  useHint.value = !useHint.value
}
// 编辑功能
const handleEdit = (row) => {
  console.log(row)
}
// 显示选中几项
const selectedTotal = ref()
// 选中的row
const selectRows = (selectRows) => {
  selectedTotal.value = selectRows.length
  console.log(selectRows)
}
const total = tableData.value.length
// 分页参数
const paginationData = ref({
  currentPage: 1,
  pageSize: 5
})
const currentTableData = ref()
// 根据分页参数计算当前显示的数据
function getPagedData(pageSize, currentPage) {
  const start = (currentPage - 1) * pageSize
  const end = start + pageSize
  const tables = []
  for (let i = start; i < end; i++) {
    if (tableData.value[i]) tables.push(tableData.value[i])
  }

  return (currentTableData.value = tables)
}
// 更新分页数据
function handlePageChange(pageSize, currentPage) {
  paginationData.value.pageSize = pageSize
  paginationData.value.currentPage = currentPage
  tableData.value = getPagedData(pageSize, currentPage)
}
</script>

<style lang="scss" scoped>
.operation {
  margin-bottom: 10px;
}
.hint {
  height: 33px;
  line-height: 33px;
  background-color: rgb(242, 250, 254);
  border: 1px solid rgb(193, 226, 252);
  border-radius: 5px;
  margin-bottom: 10px;
}
</style>
