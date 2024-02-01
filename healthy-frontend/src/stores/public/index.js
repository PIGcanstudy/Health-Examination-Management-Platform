import { defineStore } from 'pinia'
import { ref } from 'vue'
import {
  querydictnamelist,
  queryjobnamelist,
  querypackageprolist,
  querypackagepronamelist,
  queryplannamelist,
  queryplanprolist,
  queryselectionnamelist,
  querytermnamelist,
  querytypetree,
  queryuesrnamelist
} from '@/apis/public/index.js'

export const usePublicStore = defineStore('public', () => {
  // 列表数据
  const tableData = ref([])
  // 总计
  const total = ref(0)
  // 重写方法
  const getJobName = async (params) => {
    await queryJobName(params)
      .then((response) => {
        tableData.value = response.data.rows
        total.value = response.data.total
      })
      .catch((err) => {
        console.log('err', err)
      })
  }


  // 暴露出的数据
  return {
    tableData,
    total,
    querydictnamelist,
    queryjobnamelist,
    querypackageprolist,
    querypackagepronamelist,
    queryplannamelist,
    queryplanprolist,
    queryselectionnamelist,
    querytermnamelist,
    querytypetree,
    queryuesrnamelist
  }
})
